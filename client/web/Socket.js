"use strict";

let evSocketConnected = new CustomEvent('evSocketConnected');

class Socket {
    constructor() {
        this.websocket = null;

        if (typeof MozWebSocket == 'function') {
            WebSocket = MozWebSocket;
        }
        if ( this.websocket && this.websocket.readyState == 1 ) {
            this.websocket.close();
        }
    }

    init() {

        try {
            var wsUri = "ws://" + document.getElementById("webSocketHost").value;
            this.websocket = new WebSocket( wsUri );
            this.websocket.onopen    = this.onopen;
            this.websocket.onclose   = this.onclose;
            this.websocket.onmessage = this.onmessage;
            this.websocket.onerror   = this.onerror;
        } catch (exception) {
            console.log('ERROR: ' + exception);
        }
    }

    close() {
        if (this.websocket) {
            this.websocket.close();
        }
    }

    onopen (evt) {
        console.log("CONNECTED");
        document.dispatchEvent(evSocketConnected);
    };

    onclose(evt) {
        console.log("DISCONNECTED");
    };

    onmessage(evt) {
        console.log( "Message received :", evt.data );
    };

    onerror(evt) {
        console.log('ERROR: ' + evt.data);
    };
    //
    // checkSocket() {
    //     if (this.websocket != null) {
    //         var stateStr;
    //         switch (this.websocket.readyState) {
    //             case 0: {
    //                 stateStr = "CONNECTING";
    //                 break;
    //             }
    //             case 1: {
    //                 stateStr = "OPEN";
    //                 break;
    //             }
    //             case 2: {
    //                 stateStr = "CLOSING";
    //                 break;
    //             }
    //             case 3: {
    //                 stateStr = "CLOSED";
    //                 break;
    //             }
    //             default: {
    //                 stateStr = "UNKNOW";
    //                 break;
    //             }
    //         }
    //         console.log("WebSocket state = " + this.websocket.readyState + " ( " + stateStr + " )");
    //     } else {
    //         console.log("WebSocket is null");
    //     }
    // }
}