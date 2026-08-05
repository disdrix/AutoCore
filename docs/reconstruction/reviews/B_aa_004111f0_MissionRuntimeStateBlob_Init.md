# Review B (skeptical / adversarial): `aa_004111f0` MissionRuntimeStateBlob_Init

| Field | Value |
|---|---|
| **Stable ID** | `aa_004111f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004111f0_MissionRuntimeStateBlob_Init.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This function **allocates** the 0x30 blob | Body has only stores + `RET`; no `operator_new` | **Falsified** — parent allocates |
| 2 | This function **inserts** into `char+0x530` | No hash/call sites in body | **Falsified** — `FUN_0053c660` is parent |
| 3 | Decompiler `void` means no useful return | Bytes `MOV EAX,ECX`; GiveMission assigns cast return | **Falsified for ports** — **EAX = pBlob** at RET |
| 4 | Signature is truly `FUN_004111f0(void)` (no arg) | Decompile + ECX stores; `analyze_function_complete` still lists `param_1` in ECX | **Falsified** — **ECX = blob**; zero-arg Ghidra sig is under-typed |
| 5 | Full `0x30` memset to `-1` | Only **11 dwords** (`0x00`–`0x28`) + **byte `+0x2C=0`**; tail `+0x2D..+0x2F` untouched | **Overstated if claimed full memset** — **not** `memset(p,0xFF,0x30)` |
| 6 | Byte `+0x2C` is part of a dword fill | Explicit `MOV BYTE [EAX+0x2C],0` after OR ECX,-1 | **Clarify** — **byte zero**, not `0xFF` at that offset |
| 7 | Order of dword stores is ABI-required | No intermediate reads; final state only matters | **Reject order-sensitivity** for ports (final layout only) |
| 8 | Null-safe | No test on ECX | **Falsified if claimed safe** — null → fault |
| 9 | Used outside GiveMission | `get_function_xrefs` / callers → **only** `CVOGReaction_GiveMission` @ `0x00532988` | **Sole caller** in this image |
| 10 | Clean invents branches / clamps | Body is straight-line stores | **No invented CF** |
| 11 | Name implies full mission object ctor | Only sentinel-fills a small blob | **Name is role label** — not full `CVOGMission` ctor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Eleven dword `0xFFFFFFFF` + byte `+0x2C=0` | **High** | Wrong initial mission runtime state |
| Leaf / no side channels | **High** | Imaginary I/O or globals |
| ECX in / EAX out (same ptr) | **High** | Port drops return and uses wrong pointer |
| Not a full 0x30 memset | **High** | Tail bytes wrong if port memsets then overwrites incorrectly |
| Product names of slots | **Tentative** | Doc-only risk; consumers own semantics |
| Sole-caller exclusivity forever | **High for this build** | Other images may gain xrefs |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  *(u8*)(param_1 + 0xb) = 0;     // dword index 0xb → byte @ +0x2C
  param_1[8..10] = -1;           // +0x20..+0x28
  param_1[0..7]  = -1;           // +0x00..+0x1C

bytes:
  MOV EAX,ECX
  OR  ECX, -1
  MOV BYTE [EAX+0x2C], 0
  MOV [EAX+0x20/24/28], ECX
  MOV [EDX+0x00..0x1C], ECX
  RET
```

**Match.** Decompiler `param_1 + 0xb` as `undefined4*` is **byte offset 0x2C** — do not misread as byte index 11.

Parent raw assigns `local_1a4 = (undefined4*)FUN_004111f0()` with thiscall elision of ECX=`operator_new` result — consistent with register arg + EAX return, **not** a free-function with zero live inputs.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact: in-place init of GiveMission runtime state blob (0x30 alloc)
static unsafe uint* MissionRuntimeStateBlob_Init(uint* pBlob)
{
    // retail: no null check
    *((byte*)pBlob + 0x2C) = 0;
    for (int off = 0; off <= 0x28; off += 4)
        *(uint*)((byte*)pBlob + off) = 0xFFFFFFFFu;
    // does NOT write +0x2D..+0x2F
    return pBlob; // EAX
}

// Parent pattern (not this unit):
//   var p = Alloc(0x30);
//   var blob = p == null ? null : MissionRuntimeStateBlob_Init(p);
//   // maybe copy 12 dwords from prior node+0x18
//   InsertStateHash(char+0x530, *def, blob);
```

**Port traps to reject:**

- `memset(p, 0xFF, 0x30)` then forgetting byte `+0x2C = 0` (would leave `+0x2C == 0xFF`).
- `memset(p, 0, 0x30)` (wrong sentinels).
- Ignoring EAX and assuming a different out-pointer.
- Inventing hash insert / toast / objective work inside this leaf.
- Treating decompiler `void` as proof the parent assignment is dead code.

---

## 5. Residual gaps (do not block seal)

1. Semantic labels for the eleven sentinel dwords and flag byte `+0x2C` (owned by blob **consumers**).
2. Whether `operator_new` zero-fills before call in this CRT (irrelevant if this unit overwrites the documented range).
3. Runtime live hit / bit-exact PE section dump.
4. Optional Ghidra retype: `uint32_t* __fastcall(uint32_t*)`.

---

## Verdict

**accept** — adversarial review cannot break the store set or the ECX/EAX pointer contract. Main falsifications: “allocator”, “hash insert”, “full memset -1”, and “void means no return”. Sole GiveMission caller is High for this image.
