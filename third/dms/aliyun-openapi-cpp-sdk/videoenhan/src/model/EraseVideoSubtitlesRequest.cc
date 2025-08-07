/*
 * Copyright 2009-2017 Alibaba Cloud All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <alibabacloud/videoenhan/model/EraseVideoSubtitlesRequest.h>

using AlibabaCloud::Videoenhan::Model::EraseVideoSubtitlesRequest;

EraseVideoSubtitlesRequest::EraseVideoSubtitlesRequest()
    : RpcServiceRequest("videoenhan", "2020-03-20", "EraseVideoSubtitles") {
  setMethod(HttpRequest::Method::Post);
}

EraseVideoSubtitlesRequest::~EraseVideoSubtitlesRequest() {}

float EraseVideoSubtitlesRequest::getBH() const {
  return bH_;
}

void EraseVideoSubtitlesRequest::setBH(float bH) {
  bH_ = bH;
  setBodyParameter(std::string("BH"), std::to_string(bH));
}

float EraseVideoSubtitlesRequest::getBW() const {
  return bW_;
}

void EraseVideoSubtitlesRequest::setBW(float bW) {
  bW_ = bW;
  setBodyParameter(std::string("BW"), std::to_string(bW));
}

float EraseVideoSubtitlesRequest::getBX() const {
  return bX_;
}

void EraseVideoSubtitlesRequest::setBX(float bX) {
  bX_ = bX;
  setBodyParameter(std::string("BX"), std::to_string(bX));
}

float EraseVideoSubtitlesRequest::getBY() const {
  return bY_;
}

void EraseVideoSubtitlesRequest::setBY(float bY) {
  bY_ = bY;
  setBodyParameter(std::string("BY"), std::to_string(bY));
}

bool EraseVideoSubtitlesRequest::getAsync() const {
  return async_;
}

void EraseVideoSubtitlesRequest::setAsync(bool async) {
  async_ = async;
  setBodyParameter(std::string("Async"), async ? "true" : "false");
}

std::string EraseVideoSubtitlesRequest::getVideoUrl() const {
  return videoUrl_;
}

void EraseVideoSubtitlesRequest::setVideoUrl(const std::string &videoUrl) {
  videoUrl_ = videoUrl;
  setBodyParameter(std::string("VideoUrl"), videoUrl);
}

