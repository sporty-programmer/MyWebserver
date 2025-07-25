#include "webserver/RequestHandler.h"

#include <ctype.h> //NOLINT


bool RequestHandler::begin() {
    return response_provider.begin();
}


void RequestHandler::handle(EthernetClient* client) {

    auto* request = new Request();
    analyze_request(client->readStringUntil('\r'), request); // analyze request

    auto* response = new Response();
    response_provider.get(request, response); // provide response

    delete request;

    client->println(response->headers + response->text); // send response

    delete response;
}


void RequestHandler::analyze_request(const String& request_string, Request* request) {

    /* First line of HTTP-Request looks as follows: "<METHOD> <URI> <PROTOCOL-VERSION>"
     * For example: "GET /example/index.html HTTP/1.1"
     */

    // find spaces
    int spaces[2];
    spaces[0] = request_string.indexOf(' ');
    spaces[1] = request_string.indexOf(' ', spaces[0] + 1);

    // extract information
    request->method = request_string.substring(0, spaces[0]); // method is before first space

    for (int i = spaces[0] + 1; i < spaces[1]; ++i) { // iterate over method (which is between first and second space)

        if (request_string[i] != '%') { // no url encoding
            request->path += static_cast<char>(toupper(request_string[i])); // add char as upper
            continue; // go to next iteration
        }

        // handle url encoding
        String url_encoding = request_string.substring(i + 1, i + 3); // extract url encoding once for comparison

        if (url_encoding == "20") request->path += " "; // space
        else if (url_encoding == "3F") break; // cut off query parameters ("%3F" = "?" = marker for query begin)

        i += 2; // skip handled url encoding
    }

    Serial.println(request->path);
}