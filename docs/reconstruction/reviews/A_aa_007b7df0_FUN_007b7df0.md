# Review A (reconstruction fidelity): `aa_007b7df0` FUN_007b7df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7df0` |
| **VA** | `0x007b7df0` |
| **Canonical name** | `FUN_007b7df0` |
| **INFERRED product role** | `DBReader_ReleaseDataConnection` (leave / refcount−−) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_007b7df0_FUN_007b7df0.md` |
| **System** | `missions-progression` (shared DBReader bookend for table Ensures) |
| **Tools** | Ghidra `batch_decompile`, `read_memory`, `audit_globals_in_function`, `get_function_callers`, `get_function_by_address` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**DBReader connection leave** — twin of `FUN_007e1d80`. Fastcall `this` = same DB reader context. Decrements refcount at `this+0x20`. When refcount reaches **0** and `DAT_00d1793c == 0`, Releases COM objects at `this+0x28` then `this+0x24` (vtable `+0x08` = IUnknown::Release), clears those slots, and sets `*this = 0`. Always returns **0**.

Paired after every Ensure* load call for quest XP / credits / level / creature XP tables.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b7df0_FUN_007b7df0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b7df0_FUN_007b7df0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b7df0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b7df0_FUN_007b7df0.md` |
| Enter twin | `0x007e1d80` |

---

## 3. Assembly-sealed body (`read_memory` @ `0x007b7df0`, body `007b7df0`–`007b7e30`)

```text
007b7df0  56                push esi
007b7df1  8B F1             mov  esi, ecx                 ; this
007b7df3  83 46 20 FF       add  dword ptr [esi+0x20], -1 ; refcount--
007b7df7  75 34             jnz  007b7e2d                 ; still nested → ret 0
007b7df9  80 3D 3C79D100 00 cmp  byte ptr [0x00d1793c], 0
007b7e00  75 2B             jnz  007b7e2d                 ; XML mode → no COM release
007b7e02  8B 46 28          mov  eax, [esi+0x28]
007b7e05  85 C0             test eax, eax
007b7e07  74 0D             jz   007b7e16
007b7e09  C7 46 28 00000000 mov  dword ptr [esi+0x28], 0
007b7e10  8B 08             mov  ecx, [eax]
007b7e12  50                push eax
007b7e13  FF 51 08          call dword ptr [ecx+0x08]     ; Release
007b7e16  8B 46 24          mov  eax, [esi+0x24]
007b7e19  85 C0             test eax, eax
007b7e1B  74 0D             jz   007b7e2a
007b7e1D  C7 46 24 00000000 mov  dword ptr [esi+0x24], 0
007b7e24  8B 10             mov  edx, [eax]
007b7e26  50                push eax
007b7e27  FF 52 08          call dword ptr [edx+0x08]     ; Release
007b7e2A  C6 06 00          mov  byte ptr [esi], 0        ; *this = 0
007b7e2D  33 C0             xor  eax, eax
007b7e2F  5E                pop  esi
007b7e30  C3                ret
```

Full hex: `568bf1834620ff7534803d3c79d10000752b8b462885c0740dc74628000000008b0850ff51088b462485c0740dc74624000000008b1050ff5208c6060033c05ec3`

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| `refcount--` | **Yes** |
| if nonzero after dec → return 0 | **Yes** (`jnz`) |
| if `DAT_00d1793c != 0` → return 0 without Release | **Yes** |
| Release `+0x28` then `+0x24`, null stores, clear `*this` | **Yes** |
| return 0 | **Yes** |

Release order is **`+0x28` first, then `+0x24`** — inverse of typical "factory then child" open order in enter (enter fills `+0x24` then `+0x28`). **High** fidelity to raw.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Fastcall this | **High** | `mov esi,ecx` |
| Refcount `this+0x20` | **High** | Symmetric with enter |
| COM Release vtable +0x08 | **High** | Standard IUnknown |
| Null-before-Release store order | **High** | Store 0 then call with saved ptr |
| XML mode skips teardown | **High** | Matches enter skip-open |
| No enter call inside leave | **High** | Leaf helper |
| Product name | **Tentative** | Keep `FUN_007b7df0` |

---

## 6. Callers (sample)

`get_function_callers`: all five Experience/Quest ensure loaders above plus other table ensures (`FUN_00512970`, `FUN_005129b0`, inventory/skill DB paths, etc.). Shared infrastructure — not XP-specific.

---

## 7. Gaps / open

1. Confirm underflow behavior if leave without enter (wraps to `0xFFFFFFFF` then would attempt release).
2. Whether `*this` clear is only the connected byte or part of a larger bitfield (asm is `mov byte ptr [esi],0`).
3. Rename seal paired with enter.

**Verdict:** **accept-with-gaps**
