// =============================================================================
// FUN_004cbfc0 / Vector_InsertN_0x10 (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbfc0
// Address:   0x004cbfc0  (autoassault.exe, image base 0x400000)
// Agent:     W25-M OWN-ONLY 2026-07-29
// Prefer:    reconstructed-exact/Vector_InsertN_0x10.cpp
// =============================================================================

// MSVC vector insert for 16-byte POD. Full commentary in named clean.

struct Vector16 {
    void* _unused0;
    void* begin;
    void* end;
    void* cap_end;
};

struct Pod16 { unsigned d0, d1, d2, d3; };

extern "C" void FUN_004cb1d0(void);
extern "C" void* operator_new(unsigned size);
extern "C" void operator_delete(void* p);
extern "C" void* FUN_005dd920(void* first, void* last, void* dest, ...);
extern "C" void FUN_00608720(void* dest, int count, Pod16* value, ...);
extern "C" void FUN_0041d5a0(void* dest, unsigned count, Pod16* value);
extern "C" void FUN_004cb2e0(void* first, void* last, Pod16* value);
extern "C" void FUN_0051b6e0(void* first, void* mid, void* last, int byteCount);

void __thiscall FUN_004cbfc0(
    Vector16* self,
    void* insertAt,
    unsigned count,
    const Pod16* value)
{
    Pod16 tmp = *value;
    void* begin = self->begin;
    unsigned capacity_elems = begin
        ? (unsigned)(((char*)self->cap_end - (char*)begin) >> 4) : 0;
    if (count == 0) return;

    unsigned size_elems = begin
        ? (unsigned)(((char*)self->end - (char*)begin) >> 4) : 0;
    if (0x0fffffffu - size_elems < count) FUN_004cb1d0();

    if (capacity_elems < size_elems + count) {
        unsigned new_cap = capacity_elems;
        if (0x0fffffffu - (new_cap >> 1) < new_cap) new_cap = 0;
        else new_cap = new_cap + (new_cap >> 1);
        if (new_cap < size_elems + count) new_cap = size_elems + count;
        void* buf = operator_new(new_cap * 0x10);
        void* mid = FUN_005dd920(self->begin, insertAt, buf, self, insertAt);
        FUN_00608720(mid, (int)count, &tmp, self, insertAt);
        FUN_005dd920(insertAt, self->end, (char*)mid + count * 0x10, self, insertAt);
        void* old = self->begin;
        unsigned old_size = old ? (unsigned)(((char*)self->end - (char*)old) >> 4) : 0;
        if (old) operator_delete(old);
        self->cap_end = (char*)buf + new_cap * 0x10;
        self->end = (char*)buf + (count + old_size) * 0x10;
        self->begin = buf;
        return;
    }

    void* end = self->end;
    unsigned tail_elems = (unsigned)(((char*)end - (char*)insertAt) >> 4);
    if (tail_elems < count) {
        unsigned bytes = count * 0x10;
        FUN_005dd920(insertAt, end, (char*)insertAt + bytes, self, bytes);
        FUN_0041d5a0(self->end, count - tail_elems, &tmp);
        self->end = (char*)self->end + bytes;
        FUN_004cb2e0(insertAt, (char*)self->end - (int)(count * 0x10), &tmp);
        return;
    }
    {
        unsigned bytes = count * 0x10;
        void* split = (char*)end - bytes;
        void* new_end = FUN_005dd920(split, end, end, self, bytes);
        self->end = new_end;
        FUN_0051b6e0(insertAt, split, end, (int)bytes);
        FUN_004cb2e0(insertAt, (char*)insertAt + bytes, &tmp);
    }
}
