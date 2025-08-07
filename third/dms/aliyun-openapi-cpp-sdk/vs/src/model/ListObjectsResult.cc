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

#include <alibabacloud/vs/model/ListObjectsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Vs;
using namespace AlibabaCloud::Vs::Model;

ListObjectsResult::ListObjectsResult() :
	ServiceResult()
{}

ListObjectsResult::ListObjectsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListObjectsResult::~ListObjectsResult()
{}

void ListObjectsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allContentsNode = value["Contents"]["Content"];
	for (auto valueContentsContent : allContentsNode)
	{
		Content contentsObject;
		if(!valueContentsContent["Key"].isNull())
			contentsObject.key = valueContentsContent["Key"].asString();
		if(!valueContentsContent["LastModified"].isNull())
			contentsObject.lastModified = valueContentsContent["LastModified"].asString();
		if(!valueContentsContent["ETag"].isNull())
			contentsObject.eTag = valueContentsContent["ETag"].asString();
		if(!valueContentsContent["Size"].isNull())
			contentsObject.size = std::stol(valueContentsContent["Size"].asString());
		if(!valueContentsContent["StorageClass"].isNull())
			contentsObject.storageClass = valueContentsContent["StorageClass"].asString();
		contents_.push_back(contentsObject);
	}
	auto allCommonPrefixes = value["CommonPrefixes"]["Prefix"];
	for (const auto &item : allCommonPrefixes)
		commonPrefixes_.push_back(item.asString());
	if(!value["BucketName"].isNull())
		bucketName_ = value["BucketName"].asString();
	if(!value["Prefix"].isNull())
		prefix_ = value["Prefix"].asString();
	if(!value["MaxKeys"].isNull())
		maxKeys_ = std::stoi(value["MaxKeys"].asString());
	if(!value["KeyCount"].isNull())
		keyCount_ = std::stoi(value["KeyCount"].asString());
	if(!value["Delimiter"].isNull())
		delimiter_ = value["Delimiter"].asString();
	if(!value["EncodingType"].isNull())
		encodingType_ = value["EncodingType"].asString();
	if(!value["IsTruncated"].isNull())
		isTruncated_ = value["IsTruncated"].asString() == "true";
	if(!value["ContinuationToken"].isNull())
		continuationToken_ = value["ContinuationToken"].asString();
	if(!value["NextContinuationToken"].isNull())
		nextContinuationToken_ = value["NextContinuationToken"].asString();
	if(!value["Marker"].isNull())
		marker_ = value["Marker"].asString();
	if(!value["NextMarker"].isNull())
		nextMarker_ = value["NextMarker"].asString();

}

std::vector<std::string> ListObjectsResult::getCommonPrefixes()const
{
	return commonPrefixes_;
}

std::string ListObjectsResult::getNextContinuationToken()const
{
	return nextContinuationToken_;
}

std::string ListObjectsResult::getContinuationToken()const
{
	return continuationToken_;
}

std::string ListObjectsResult::getDelimiter()const
{
	return delimiter_;
}

std::string ListObjectsResult::getEncodingType()const
{
	return encodingType_;
}

bool ListObjectsResult::getIsTruncated()const
{
	return isTruncated_;
}

std::string ListObjectsResult::getPrefix()const
{
	return prefix_;
}

std::string ListObjectsResult::getMarker()const
{
	return marker_;
}

std::vector<ListObjectsResult::Content> ListObjectsResult::getContents()const
{
	return contents_;
}

std::string ListObjectsResult::getBucketName()const
{
	return bucketName_;
}

int ListObjectsResult::getMaxKeys()const
{
	return maxKeys_;
}

int ListObjectsResult::getKeyCount()const
{
	return keyCount_;
}

std::string ListObjectsResult::getNextMarker()const
{
	return nextMarker_;
}

