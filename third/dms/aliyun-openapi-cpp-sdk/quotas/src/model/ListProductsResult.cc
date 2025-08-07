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

#include <alibabacloud/quotas/model/ListProductsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Quotas;
using namespace AlibabaCloud::Quotas::Model;

ListProductsResult::ListProductsResult() :
	ServiceResult()
{}

ListProductsResult::ListProductsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListProductsResult::~ListProductsResult()
{}

void ListProductsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allProductInfoNode = value["ProductInfo"]["ProductInfos"];
	for (auto valueProductInfoProductInfos : allProductInfoNode)
	{
		ProductInfos productInfoObject;
		if(!valueProductInfoProductInfos["ProductName"].isNull())
			productInfoObject.productName = valueProductInfoProductInfos["ProductName"].asString();
		if(!valueProductInfoProductInfos["SecondCategoryId"].isNull())
			productInfoObject.secondCategoryId = std::stol(valueProductInfoProductInfos["SecondCategoryId"].asString());
		if(!valueProductInfoProductInfos["ProductNameEn"].isNull())
			productInfoObject.productNameEn = valueProductInfoProductInfos["ProductNameEn"].asString();
		if(!valueProductInfoProductInfos["Dynamic"].isNull())
			productInfoObject.dynamic = valueProductInfoProductInfos["Dynamic"].asString() == "true";
		if(!valueProductInfoProductInfos["SecondCategoryNameEn"].isNull())
			productInfoObject.secondCategoryNameEn = valueProductInfoProductInfos["SecondCategoryNameEn"].asString();
		if(!valueProductInfoProductInfos["SecondCategoryName"].isNull())
			productInfoObject.secondCategoryName = valueProductInfoProductInfos["SecondCategoryName"].asString();
		if(!valueProductInfoProductInfos["ProductCode"].isNull())
			productInfoObject.productCode = valueProductInfoProductInfos["ProductCode"].asString();
		if(!valueProductInfoProductInfos["FlowControlSupport"].isNull())
			productInfoObject.flowControlSupport = valueProductInfoProductInfos["FlowControlSupport"].asString();
		if(!valueProductInfoProductInfos["CommonQuotaSupport"].isNull())
			productInfoObject.commonQuotaSupport = valueProductInfoProductInfos["CommonQuotaSupport"].asString();
		if(!valueProductInfoProductInfos["WhiteListLabelQuotaSupport"].isNull())
			productInfoObject.whiteListLabelQuotaSupport = valueProductInfoProductInfos["WhiteListLabelQuotaSupport"].asString();
		productInfo_.push_back(productInfoObject);
	}
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());
	if(!value["NextToken"].isNull())
		nextToken_ = value["NextToken"].asString();
	if(!value["MaxResults"].isNull())
		maxResults_ = std::stoi(value["MaxResults"].asString());

}

std::vector<ListProductsResult::ProductInfos> ListProductsResult::getProductInfo()const
{
	return productInfo_;
}

int ListProductsResult::getTotalCount()const
{
	return totalCount_;
}

std::string ListProductsResult::getNextToken()const
{
	return nextToken_;
}

int ListProductsResult::getMaxResults()const
{
	return maxResults_;
}

