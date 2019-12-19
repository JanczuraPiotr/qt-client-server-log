"use strict";


class Main {

    constructor() {
        this.socket = null;

        this.buttonConnect = document.getElementById("buttonConnect");
        this.buttonDisconnect = document.getElementById("buttonDisconnect");
        this.textArea = document.getElementById("textArea");
        this.commandText = document.getElementById("commandText");
        this.commandButton = document.getElementById("commandButton");

        this.commandButton.disabled = true;
        this.buttonConnect.disabled = false;
        this.buttonDisconnect.disabled = true;

        this.buttonConnect.onclick = this.buttonConnectOnClick();
        this.buttonDisconnect.onclick = this.buttonDisconnectOnClick();
        this.commandButton.onclick = this.commandButtonOnClick();

        document.addEventListener('evSocketConnected', this.onSocketConnected());
        document.addEventListener('evSocketDisconnected', this.onSocketDisconnected());
        document.addEventListener('evMessageReceived', this.onMessageReceived());
    }

    buttonConnectOnClick() {
        let obj = this;
        return (function() {
            console.log("Main.buttonConnect.onclick");
            obj.socket = new Socket();
            obj.socket.init();
        });
    }

    buttonDisconnectOnClick() {
        let obj = this;
        return (function () {
            console.log("Main.buttonDisconnect.onclick");
            if (obj.socket) {
                obj.socket.close();
                obj.socket = null;
            }
        })
    }

    commandButtonOnClick() {
        let obj = this;
        return (function(){
            console.log("Main.commandButton.onclick");
            obj.sendMessage(obj.commandText.value);
            obj.commandText.value = "";
        });
    };

    sendMessage(strToSend) {
        var msg = this.commandText.value;
        if ( this.socket != null )
        {
            this.socket.send( msg );
            console.log( "string sent :", '"'+strToSend+'"' );
            //this.debug(strToSend);
        }
    }

    debug(message) {
        this.textArea.value += message + "\n";
        this.textArea.scrollTop = this.textArea.scrollHeight;
    }

    onSocketConnected() {
        let obj = this;
        return (function () {
            console.log("event : socketConnected");
            obj.buttonConnect.disabled = true;
            obj.buttonDisconnect.disabled = false;
            obj.commandButton.disabled = false;
        });
    }

    onSocketDisconnected() {
        let obj = this;
        return (function () {
            console.log("event : socketDisconnected");
            obj.buttonConnect.disabled = false;
            obj.buttonDisconnect.disabled = true;
            obj.commandButton.disabled = true;
        });
    }

    onMessageReceived() {
        let obj = this;
        return (function (e) {
            console.info('odebrano log', e.detail);
            obj.textArea.append(e.detail);
            obj.textArea.append('\n');
            obj.textArea.scrollTop = obj.textArea.scrollHeight
        });
    }
}
