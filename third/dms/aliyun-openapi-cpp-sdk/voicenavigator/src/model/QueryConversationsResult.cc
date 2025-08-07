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

#include <alibabacloud/voicenavigator/model/QueryConversationsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::VoiceNavigator;
using namespace AlibabaCloud::VoiceNavigator::Model;

QueryConversationsResult::QueryConversationsResult() :
	ServiceResult()
{}

QueryConversationsResult::QueryConversationsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

QueryConversationsResult::~QueryConversationsResult()
{}

void QueryConversationsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allConversationsNode = value["Conversations"]["Conversation"];
	for (auto valueConversationsConversation : allConversationsNode)
	{
		Conversation conversationsObject;
		if(!valueConversationsConversation["EndTime"].isNull())
			conversationsObject.endTime = std::stol(valueConversationsConversation["EndTime"].asString());
		if(!valueConversationsConversation["EffectiveAnswerCount"].isNull())
			conversationsObject.effectiveAnswerCount = std::stoi(valueConversationsConversation["EffectiveAnswerCount"].asString());
		if(!valueConversationsConversation["TransferredToAgent"].isNull())
			conversationsObject.transferredToAgent = valueConversationsConversation["TransferredToAgent"].asString() == "true";
		if(!valueConversationsConversation["BeginTime"].isNull())
			conversationsObject.beginTime = std::stol(valueConversationsConversation["BeginTime"].asString());
		if(!valueConversationsConversation["SkillGroupId"].isNull())
			conversationsObject.skillGroupId = valueConversationsConversation["SkillGroupId"].asString();
		if(!valueConversationsConversation["ConversationId"].isNull())
			conversationsObject.conversationId = valueConversationsConversation["ConversationId"].asString();
		if(!valueConversationsConversation["CallingNumber"].isNull())
			conversationsObject.callingNumber = valueConversationsConversation["CallingNumber"].asString();
		if(!valueConversationsConversation["UserUtteranceCount"].isNull())
			conversationsObject.userUtteranceCount = std::stoi(valueConversationsConversation["UserUtteranceCount"].asString());
		conversations_.push_back(conversationsObject);
	}
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stol(value["TotalCount"].asString());
	if(!value["PageSize"].isNull())
		pageSize_ = std::stoi(value["PageSize"].asString());
	if(!value["PageNumber"].isNull())
		pageNumber_ = std::stoi(value["PageNumber"].asString());

}

long QueryConversationsResult::getTotalCount()const
{
	return totalCount_;
}

int QueryConversationsResult::getPageSize()const
{
	return pageSize_;
}

int QueryConversationsResult::getPageNumber()const
{
	return pageNumber_;
}

std::vector<QueryConversationsResult::Conversation> QueryConversationsResult::getConversations()const
{
	return conversations_;
}

