# Annotated low-level: Phy_CPConnectionPair_ReleaseClear

| Field | Value |
|---|---|
| Stable ID | `aa_0044adc0` |
| VA | `0x0044adc0`–`0x0044ae50` |
| Ghidra name | `FUN_0044adc0` |
| Canonical name | `Phy_CPConnectionPair_ReleaseClear` |
| System | physics-cpconnection |
| Date | 2026-07-29 (W22-S dual seal) |
| Tools | `decompile_function`, `analyze_function_complete`, `read_memory` — **no** `disassemble_bytes` |

---

## Purpose

Tear down a **dual connection-point bind pair** block:

1. Clear raw owner-out at `+0x08`.
2. Release refcounted object at `+0x0C` (smart slot B) via `refcount--` / `vtbl+8` if zero; clear slot.
3. Clear raw owner-out at `+0x00`.
4. Release refcounted object at `+0x04` (smart slot A); clear slot.
5. Call `FUN_00437150` on both smart-slot addresses (already null → no-op; SEH / template dtor residue).

Matches the pair layout filled by `Phy_CPConnection_AssertConnectionPoint` (`0x0044af00`): owner outs at `+0`/`+8`, smart slots at `+4`/`+0xC`. Callers use this on attach failure and special-event cleanup.

**Not** a heap free of the pair block itself (callers `delete` separately). **Not** AddRef.

---

## Signature (byte-sealed ABI)

```c
// __stdcall, 1 stack arg, ret 4
// SEH frame with handler LAB_009bcaea
void __stdcall Phy_CPConnectionPair_ReleaseClear(CPConnectionPair *pair);
```

| Formal | Source | Conf |
|---|---|---|
| `pair` | stack `[esp+4]` after SEH → **ESI** | **High** |
| Return | void (`ret 4`) | **High** |
| Calling convention | **`__stdcall`** (bytes `C2 04 00`) | **High** |

### Pair layout (byte-sealed offsets)

| Off | Role | Action |
|---|---|---|
| `+0x00` | owner/raw out 1 | store 0 (no Release) |
| `+0x04` | refcounted* A | refcount protocol + clear |
| `+0x08` | owner/raw out 2 | store 0 first |
| `+0x0C` | refcounted* B | refcount protocol + clear |

### Ref protocol (per smart object)

```
obj = *slot
if obj:
  obj->refcount at +4  -= 1   // add dword [ecx+4], -1
  if refcount == 0:
    call [(*obj)+8]           // vtbl Release-like
  *slot = 0
```

---

## Pseudocode (annotated ≡ raw ≡ bytes)

```c
void __stdcall Phy_CPConnectionPair_ReleaseClear(uint32_t *pair /*ESI*/)
{
    // SEH install (fs:[0], state=1) omitted for readability
    uint32_t *slotB = pair + 3; // +0x0C
    pair[2] = 0;                // +0x08

    int *objB = (int *)*slotB;
    if (objB) {
        if (--objB[1] == 0)
            ((void (__thiscall **)(int *))(*objB))[2](objB); // vtbl+8
        *slotB = 0;
    }

    pair[0] = 0; // +0x00

    int *objA = (int *)pair[1]; // +0x04
    if (objA) {
        if (--objA[1] == 0)
            ((void (__thiscall **)(int *))(*objA))[2](objA);
        pair[1] = 0;
    }

    FUN_00437150((int *)slotB);     // already 0
    FUN_00437150((int *)(pair + 1)); // already 0
    // SEH uninstall; ret 4
}
```

---

## Machine notes

- Sole callee: `FUN_00437150` @ `0x00437150` (×2, rel32 sealed).
- Decompiler shows `void` without `ret 4`; bytes prove stdcall.
- Inline Release before `FUN_00437150` means the helper usually no-ops in the success path of this unit — still part of retail CF.
- 7 callers across physics pair sites + `ClientSpecialEvent_*` teardown.

---

## Open questions

1. Exact product C++ type name of the pair block (layout sealed; typedef Probable via `phyCPConnection.h` sibling).
2. Semantic name of `vtbl+8` (Release vs destroy) — protocol shape High, English Probable.
3. Why `FUN_00437150` is always called after clear (template / SEH state machine) — residual, not blocking.
4. Runtime / bit-exact.
