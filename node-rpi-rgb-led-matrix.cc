// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
//
// This code is public domain
// (but note, that the led-matrix library this depends on is GPL v2)

#include "led-matrix.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>

#include <nan.h>
#include <errno.h>

using v8::FunctionTemplate;
// using v8::Handle;
// using v8::Object;
using v8::String;

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

using Nan::GetFunction;
using Nan::New;
using Nan::Set;

Canvas *canvas;
GPIO io;

NAN_METHOD(start) {
  int rows = info[0]->IntegerValue();
  int chain = info[1]->IntegerValue();
  canvas = new RGBMatrix(&io, rows, chain);
  info.GetReturnValue().SetUndefined();
}

NAN_METHOD(stop) {
  canvas->Clear();
  delete canvas;
  info.GetReturnValue().SetUndefined();
}


NAN_METHOD(fill) {
  int r = info[0]->IntegerValue();
  int g = info[1]->IntegerValue();
  int b = info[2]->IntegerValue();
  canvas->Fill(r, g, b);
  info.GetReturnValue().SetUndefined();
}

NAN_METHOD(setPixel) {
  int x = info[0]->IntegerValue();
  int y = info[1]->IntegerValue();
  int r = info[2]->IntegerValue();
  int g = info[3]->IntegerValue();
  int b = info[4]->IntegerValue();
  canvas->SetPixel(x, y, r, g, b);
  info.GetReturnValue().SetUndefined();
}

NAN_METHOD(clear) {
  canvas->Clear();
  info.GetReturnValue().SetUndefined();
}

NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("start").ToLocalChecked(), GetFunction(New<FunctionTemplate>(start)).ToLocalChecked());
  Set(target, New<String>("stop").ToLocalChecked(), GetFunction(New<FunctionTemplate>(stop)).ToLocalChecked());
  Set(target, New<String>("fill").ToLocalChecked(), GetFunction(New<FunctionTemplate>(fill)).ToLocalChecked());
  Set(target, New<String>("setPixel").ToLocalChecked(), GetFunction(New<FunctionTemplate>(setPixel)).ToLocalChecked());
  Set(target, New<String>("clear").ToLocalChecked(), GetFunction(New<FunctionTemplate>(clear)).ToLocalChecked());

  io.Init();
}

NODE_MODULE(rpi_rgb_led_matrix, InitAll);
