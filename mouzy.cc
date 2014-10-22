#include <node.h>
#include <v8.h>

/* Mouse moving */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace v8;

Handle<Value> Move(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    INPUT b[1];
    b->type = INPUT_MOUSE;
    b->mi.mouseData = 0;
    b->mi.dwFlags = MOUSEEVENTF_MOVE;
    b->mi.time = 0;
    b->mi.dwExtraInfo = 0;

    b->mi.dx = args[0]->NumberValue();
    b->mi.dy = args[1]->NumberValue();

    SendInput(1, b, sizeof(INPUT));

    return scope.Close(Undefined());
}


Handle<Value> Click(const Arguments& args) {
    HandleScope scope;

    if (args.Length() > 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    INPUT b[1];
    b->type = INPUT_MOUSE;
    b->mi.mouseData = 0;
    b->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    b->mi.time = 0;
    b->mi.dwExtraInfo = 0;

    SendInput(1, b, sizeof(INPUT));

    Sleep(10);

    b->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, b, sizeof(INPUT));

    return scope.Close(Undefined());
}



void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("move"), FunctionTemplate::New(Move)->GetFunction());
    exports->Set(String::NewSymbol("click"), FunctionTemplate::New(Click)->GetFunction());
}

NODE_MODULE(mouzy, init)