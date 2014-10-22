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

Handle<Value> move(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    POINT p;
    GetCursorPos(&p);
    p.x += args[0]->NumberValue();
    p.y += args[1]->NumberValue();

    SetCursorPos(p.x, p.y);

    return scope.Close(Undefined());
}

Handle<Value> setPosition(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    SetCursorPos(args[0]->NumberValue(), args[1]->NumberValue());

    return scope.Close(Undefined());
}


Handle<Value> click(const Arguments& args) {
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
    exports->Set(String::NewSymbol("setPosition"), FunctionTemplate::New(setPosition)->GetFunction());
    exports->Set(String::NewSymbol("click"), FunctionTemplate::New(click)->GetFunction());
    exports->Set(String::NewSymbol("move"), FunctionTemplate::New(move)->GetFunction());
}

NODE_MODULE(mouzy_win, init)