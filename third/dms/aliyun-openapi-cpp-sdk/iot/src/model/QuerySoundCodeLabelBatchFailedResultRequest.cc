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

#include <alibabacloud/iot/model/QuerySoundCodeLabelBatchFailedResultRequest.h>

using AlibabaCloud::Iot::Model::QuerySoundCodeLabelBatchFailedResultRequest;

QuerySoundCodeLabelBatchFailedResultRequest::QuerySoundCodeLabelBatchFailedResultRequest() :
	RpcServiceRequest("iot", "2018-01-20", "QuerySoundCodeLabelBatchFailedResult")
{
	setMethod(HttpRequest::Method::Post);
}

QuerySoundCodeLabelBatchFailedResultRequest::~QuerySoundCodeLabelBatchFailedResultRequest()
{}

std::string QuerySoundCodeLabelBatchFailedResultRequest::getBatchCode()const
{
	return batchCode_;
}

void QuerySoundCodeLabelBatchFailedResultRequest::setBatchCode(const std::string& batchCode)
{
	batchCode_ = batchCode;
	setBodyParameter("BatchCode", batchCode);
}

std::string QuerySoundCodeLabelBatchFailedResultRequest::getIotInstanceId()const
{
	return iotInstanceId_;
}

void QuerySoundCodeLabelBatchFailedResultRequest::setIotInstanceId(const std::string& iotInstanceId)
{
	iotInstanceId_ = iotInstanceId;
	setBodyParameter("IotInstanceId", iotInstanceId);
}

std::string QuerySoundCodeLabelBatchFailedResultRequest::getApiProduct()const
{
	return apiProduct_;
}

void QuerySoundCodeLabelBatchFailedResultRequest::setApiProduct(const std::string& apiProduct)
{
	apiProduct_ = apiProduct;
	setBodyParameter("ApiProduct", apiProduct);
}

std::string QuerySoundCodeLabelBatchFailedResultRequest::getApiRevision()const
{
	return apiRevision_;
}

void QuerySoundCodeLabelBatchFailedResultRequest::setApiRevision(const std::string& apiRevision)
{
	apiRevision_ = apiRevision;
	setBodyParameter("ApiRevision", apiRevision);
}

