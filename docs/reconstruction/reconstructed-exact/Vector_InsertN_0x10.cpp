// =============================================================================
// Vector_InsertN_0x10
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbfc0
// Address:   0x004cbfc0 – 0x004cc21c  (autoassault.exe, image base 0x400000)
// System:    MSVC STL vector insert (element size 0x10)
// Agent:     W25-M OWN-ONLY dual A/B 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + SEH/ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE:
//   Insert `count` copies of a 16-byte POD value at insertAt inside a
//   begin/end/capacity vector (pointers at this+4 / +8 / +0xc).
//   Reallocates with 1.5× growth when needed; throws "vector<T> too long"
//   via FUN_004cb1d0 when size would exceed 0x0fffffff elements.
//
// ABI: thiscall; stack insertAt, count, value*; ret 0xc; void.

struct Vector16 {
    void* _unused0;   // this+0 — not touched here
    void* begin;      // +4
    void* end;        // +8
    void* cap_end;    // +0xc
};

struct Pod16 {
    unsigned d0, d1, d2, d3;
};

extern "C" void FUN_004cb1d0(void); // throw vector<T> too long
extern "C" void* operator_new(unsigned size);
extern "C" void operator_delete(void* p);
// uninitialized_copy range of Pod16:
extern "C" void* FUN_005dd920(void* first, void* last, void* dest, ...);
// fill-n Pod16 with value:
extern "C" void FUN_00608720(void* dest, int count, Pod16* value, ...);
extern "C" void FUN_0041d5a0(void* dest, unsigned count, Pod16* value);
extern "C" void FUN_004cb2e0(void* first, void* last, Pod16* value);
extern "C" void FUN_0051b6e0(void* first, void* mid, void* last, int byteCount);

void __thiscall Vector_InsertN_0x10(
    Vector16* self,
    void* insertAt,
    unsigned count,
    const Pod16* value)
{
    Pod16 tmp = *value;
    void* begin = self->begin;

    unsigned capacity_elems = 0;
    if (begin) {
        capacity_elems = (unsigned)(((char*)self->cap_end - (char*)begin) >> 4);
    }

    if (count == 0) {
        return;
    }

    unsigned size_elems = 0;
    if (begin) {
        size_elems = (unsigned)(((char*)self->end - (char*)begin) >> 4);
    }

    // overflow guard — decomp: if (0x0fffffff - size < count) throw
    if (0x0fffffffu - size_elems < count) {
        FUN_004cb1d0();
    }

    if (capacity_elems < size_elems + count) {
        unsigned new_cap = capacity_elems;
        if (0x0fffffffu - (new_cap >> 1) < new_cap) {
            new_cap = 0;
        } else {
            new_cap = new_cap + (new_cap >> 1);
        }
        if (new_cap < size_elems + count) {
            new_cap = size_elems + count;
        }
        void* buf = operator_new(new_cap * 0x10);
        void* mid = FUN_005dd920(self->begin, insertAt, buf, self, insertAt);
        FUN_00608720(mid, (int)count, &tmp, self, insertAt);
        FUN_005dd920(insertAt, self->end,
                     (char*)mid + count * 0x10, self, insertAt);
        void* old = self->begin;
        unsigned old_size = 0;
        if (old) {
            old_size = (unsigned)(((char*)self->end - (char*)old) >> 4);
        }
        if (old) {
            operator_delete(old);
        }
        self->cap_end = (char*)buf + new_cap * 0x10;
        self->end = (char*)buf + (count + old_size) * 0x10;
        self->begin = buf;
        return;
    }

    // capacity sufficient — two in-place shapes (see raw decompile)
    void* end = self->end;
    unsigned tail_elems = (unsigned)(((char*)end - (char*)insertAt) >> 4);
    if (tail_elems < count) {
        unsigned bytes = count * 0x10;
        FUN_005dd920(insertAt, end, (char*)insertAt + bytes, self, bytes);
        // SEH level 2 around fill of brand-new suffix
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

void __thiscall FUN_004cbfc0(
    Vector16* self, void* insertAt, unsigned count, const Pod16* value)
{
    Vector_InsertN_0x10(self, insertAt, count, value);
}
