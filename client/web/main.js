"use strict";


class Main {

    constructor() {
        this.socket = null;

        this.buttonConnect = document.getElementById("buttonConnect");
        this.buttonDisconnect = document.getElementById("buttonDisconnect");
        this.textArea = document.getElementById("textArea");
        this.commandText = document.getElementById("commandText");
        this.commandButton = document.getElementById("commandButton");

        this.buttonConnect.onclick = this.buttonConnectOnClick;
        this.buttonDisconnect.onclick = this.buttonDisconnectOnClick;
        this.commandButton.onclick = this.commandButtonOnClick;

        document.addEventListener('evSocketConnected', this.onSocketConnected);
    }

    buttonConnectOnClick() {
        console.log("Main.buttonConnect.onclick");
        this.socket = new Socket();
        this.socket.init();
    }

    buttonDisconnectOnClick() {
        console.log("Main.buttonDisconnect.onclick");
        if (this.socket) {
            this.socket.Close();
            this.socket = null;
        }
    }

    commandButtonOnClick() {
        console.log("Main.commandButton.onclick");
    };

    sendMessage() {
        var msg = this.commandText.value;
        if ( this.websocket != null )
        {
            //document.getElementById("inputText").value = "";
            this.websocket.send( msg );
            console.log( "string sent :", '"'+strToSend+'"' );
            this.debug(strToSend);
        }
    }

    debug(message) {
        this.textArea.value += message + "\n";
        this.textArea.scrollTop = this.textArea.scrollHeight;
    }

    onSocketConnected() {
        console.log("event : socketConnected");
        this.buttonConnect.disabled = true;
        this.buttonDisconnect.disabled = false;
        //document.getElementById("buttonConnect").disabled = true;
    }
}

