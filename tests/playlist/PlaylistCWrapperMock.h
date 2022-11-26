#pragma once

#include <PlaylistCWrapper.h>

#include <gmock/gmock.h>

class PlaylistCWrapperMock : public PlaylistCWrapper
{
public:
    PlaylistCWrapperMock() : PlaylistCWrapper(nullptr) {};

    // PlaylistCWrapper members
    MOCK_METHOD(void, Connect, (projectm_handle));

    // Playlist members
    MOCK_METHOD(uint32_t, Size, (), (const));
    MOCK_METHOD(bool, Empty, (), (const));
    MOCK_METHOD(void, Clear, ());
    MOCK_METHOD(const std::vector<ProjectM::Playlist::Item>&, Items, (), (const));
    MOCK_METHOD(bool, AddItem, (const std::string&, uint32_t, bool));
    MOCK_METHOD(uint32_t, AddPath, (const std::string&, uint32_t, bool, bool));
    MOCK_METHOD(bool, RemoveItem, (uint32_t));
    MOCK_METHOD(void, SetShuffle, (bool));
    MOCK_METHOD(void, Sort, (uint32_t, uint32_t, SortPredicate, SortOrder));
    MOCK_METHOD(uint32_t, RetryCount, ());
    MOCK_METHOD(void, SetRetryCount, (uint32_t));
    MOCK_METHOD(size_t, PresetIndex, (), (const));
    MOCK_METHOD(size_t, SetPresetIndex, (size_t));
    MOCK_METHOD(void, PlayPresetIndex, (size_t, bool, bool));
};
