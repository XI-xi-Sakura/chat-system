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

#include <alibabacloud/cloudauth/model/DescribeVerifyResultResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cloudauth;
using namespace AlibabaCloud::Cloudauth::Model;

DescribeVerifyResultResult::DescribeVerifyResultResult() :
	ServiceResult()
{}

DescribeVerifyResultResult::DescribeVerifyResultResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeVerifyResultResult::~DescribeVerifyResultResult()
{}

void DescribeVerifyResultResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto materialNode = value["Material"];
	if(!materialNode["IdCardNumber"].isNull())
		material_.idCardNumber = materialNode["IdCardNumber"].asString();
	if(!materialNode["FaceGlobalUrl"].isNull())
		material_.faceGlobalUrl = materialNode["FaceGlobalUrl"].asString();
	if(!materialNode["FaceImageUrl"].isNull())
		material_.faceImageUrl = materialNode["FaceImageUrl"].asString();
	if(!materialNode["FaceMask"].isNull())
		material_.faceMask = materialNode["FaceMask"].asString() == "true";
	if(!materialNode["IdCardName"].isNull())
		material_.idCardName = materialNode["IdCardName"].asString();
	if(!materialNode["FaceQuality"].isNull())
		material_.faceQuality = materialNode["FaceQuality"].asString();
	auto idCardInfoNode = materialNode["IdCardInfo"];
	if(!idCardInfoNode["Sex"].isNull())
		material_.idCardInfo.sex = idCardInfoNode["Sex"].asString();
	if(!idCardInfoNode["EndDate"].isNull())
		material_.idCardInfo.endDate = idCardInfoNode["EndDate"].asString();
	if(!idCardInfoNode["Authority"].isNull())
		material_.idCardInfo.authority = idCardInfoNode["Authority"].asString();
	if(!idCardInfoNode["Address"].isNull())
		material_.idCardInfo.address = idCardInfoNode["Address"].asString();
	if(!idCardInfoNode["Number"].isNull())
		material_.idCardInfo.number = idCardInfoNode["Number"].asString();
	if(!idCardInfoNode["StartDate"].isNull())
		material_.idCardInfo.startDate = idCardInfoNode["StartDate"].asString();
	if(!idCardInfoNode["BackImageUrl"].isNull())
		material_.idCardInfo.backImageUrl = idCardInfoNode["BackImageUrl"].asString();
	if(!idCardInfoNode["Nationality"].isNull())
		material_.idCardInfo.nationality = idCardInfoNode["Nationality"].asString();
	if(!idCardInfoNode["Birth"].isNull())
		material_.idCardInfo.birth = idCardInfoNode["Birth"].asString();
	if(!idCardInfoNode["Name"].isNull())
		material_.idCardInfo.name = idCardInfoNode["Name"].asString();
	if(!idCardInfoNode["FrontImageUrl"].isNull())
		material_.idCardInfo.frontImageUrl = idCardInfoNode["FrontImageUrl"].asString();
		auto allVideoUrls = materialNode["VideoUrls"]["VideoUrl"];
		for (auto value : allVideoUrls)
			material_.videoUrls.push_back(value.asString());
	if(!value["AuthorityComparisionScore"].isNull())
		authorityComparisionScore_ = std::stof(value["AuthorityComparisionScore"].asString());
	if(!value["VerifyStatus"].isNull())
		verifyStatus_ = std::stoi(value["VerifyStatus"].asString());
	if(!value["FaceComparisonScore"].isNull())
		faceComparisonScore_ = std::stof(value["FaceComparisonScore"].asString());
	if(!value["IdCardFaceComparisonScore"].isNull())
		idCardFaceComparisonScore_ = std::stof(value["IdCardFaceComparisonScore"].asString());

}

int DescribeVerifyResultResult::getVerifyStatus()const
{
	return verifyStatus_;
}

DescribeVerifyResultResult::Material DescribeVerifyResultResult::getMaterial()const
{
	return material_;
}

float DescribeVerifyResultResult::getAuthorityComparisionScore()const
{
	return authorityComparisionScore_;
}

float DescribeVerifyResultResult::getFaceComparisonScore()const
{
	return faceComparisonScore_;
}

float DescribeVerifyResultResult::getIdCardFaceComparisonScore()const
{
	return idCardFaceComparisonScore_;
}

