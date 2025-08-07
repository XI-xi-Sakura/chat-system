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

#include <alibabacloud/imm/model/AddStoryFilesRequest.h>

using AlibabaCloud::Imm::Model::AddStoryFilesRequest;

AddStoryFilesRequest::AddStoryFilesRequest()
    : RpcServiceRequest("imm", "2020-09-30", "AddStoryFiles") {
  setMethod(HttpRequest::Method::Post);
}

AddStoryFilesRequest::~AddStoryFilesRequest() {}

std::string AddStoryFilesRequest::getDatasetName() const {
  return datasetName_;
}

void AddStoryFilesRequest::setDatasetName(const std::string &datasetName) {
  datasetName_ = datasetName;
  setBodyParameter(std::string("DatasetName"), datasetName);
}

std::string AddStoryFilesRequest::getProjectName() const {
  return projectName_;
}

void AddStoryFilesRequest::setProjectName(const std::string &projectName) {
  projectName_ = projectName;
  setBodyParameter(std::string("ProjectName"), projectName);
}

std::vector<AddStoryFilesRequest::Files> AddStoryFilesRequest::getFiles() const {
  return files_;
}

void AddStoryFilesRequest::setFiles(const std::vector<AddStoryFilesRequest::Files> &files) {
  files_ = files;
  for(int dep1 = 0; dep1 != files.size(); dep1++) {
    setBodyParameter(std::string("Files") + "." + std::to_string(dep1 + 1) + ".URI", files[dep1].uRI);
  }
}

std::string AddStoryFilesRequest::getObjectId() const {
  return objectId_;
}

void AddStoryFilesRequest::setObjectId(const std::string &objectId) {
  objectId_ = objectId;
  setBodyParameter(std::string("ObjectId"), objectId);
}

