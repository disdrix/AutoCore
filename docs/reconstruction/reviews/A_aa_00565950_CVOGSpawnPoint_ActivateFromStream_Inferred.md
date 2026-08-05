# Review A (reconstruction fidelity): `aa_00565950` CVOGSpawnPoint_ActivateFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00565950` |
| **VA** | `0x00565950`–`0x00566485` (**2870 B / `0xB36`**) |
| **Canonical name** | `CVOGSpawnPoint_ActivateFromStream_Inferred` |
| **Ghidra name** | `FUN_00565950` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W30-H) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00565950_CVOGSpawnPoint_ActivateFromStream_Inferred.md` |
| **System** | client spawn-point stream unpack + activation |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Unpack a **versioned** spawn-point activation payload from a stream into a CVOGSpawnPoint MI subobject:

1. Null stream → return **0**.
2. Pre-hook vtbl+`0xB0` on adjusted object base.
3. Stream-read position float4; **add** caller world offset float4.
4. Stream-read range/flags/versioned tables (12×0xC slots, optional name, etc.).
5. If activation range ≤ 0: log **BAD SPAWN POINT ACTIVATION RANGE**, set range = **75.0f**.
6. Conditionally spawn linked entities; insert race/slot maps (`FUN_00567860`×2 per active slot).
7. Return **1**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00565950_FUN_00565950.md` (+ W30-H append) |
| Annotated | `docs/reconstruction/raw/aa_00565950_FUN_00565950.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGSpawnPoint_ActivateFromStream_Inferred.cpp` |
| Clean twin (full body) | `docs/reconstruction/reconstructed-exact/FUN_00565950.cpp` |
| Function | `docs/reconstruction/functions/aa_00565950_*` |
| Live | decompile ≡ raw CF; body bounds; epilogue `C2 10 00`; `DAT_009d2eb8`=75.0f |
| Nested | W29-M `StdMap_InsertAlways_Val12_IntKey` @ two call sites |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 2870 B | **Confirmed** | `get_function_by_address` + pad `CC` |
| thiscall + **`ret 0x10`** | **Confirmed** | entry `mov esi,ecx`; epilogue `C2 10 00` |
| Return 0/1 | **Confirmed** | early `xor al,al`; success `mov al,1` |
| Stream null gate | **Confirmed** | entry `test ebx,ebx` on `[ebp+8]` |
| Product strings | **Confirmed** | sprintf formats in body |
| Default range 75.0f | **Confirmed** | `read_memory` `00 00 96 42` |
| MI thunk entry | **Confirmed** | `0x00567CBE` jmp to body |
| CVOGSpawnPoint class English | **Inferred** | strings + neighbor named spawn fns |
| Full version field atlas | **Tentative** | large; gaps OK |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Null stream → 0 | **Yes** |
| Stream reads + offset add | **Yes** |
| Range clamp + debug string | **Yes** |
| Version-gated tables / spawn / maps | **Yes** (CF) |
| Success return 1 + `ret 0x10` | **Yes** |

### 4.1 Sealed contract

```
// thiscall; ret 0x10
uint32_t CVOGSpawnPoint_ActivateFromStream_Inferred(
    void *spawn_subobject, void *stream, int version, float *world_offset4);
// stream==null → 0; else unpack+activate → 1
// range<=0 → 75.0f; maps via InsertAlways Val12
```

---

## 5. Callers / callees (live)

**CODE entry:** sole direct xref from MI adjustor thunk `0x00567CBE` (vtable-facing).  
**Callees:** stream vtbl+`0x14`; sprintf/OutputDebugStringA; `FUN_00567860` (W29-M); `FUN_0040b330`; `Object_GetRootRaceId`; spawn helpers; alloc/register paths.

---

## 6. Gaps

1. Complete product field names / version schema table.  
2. Fourth stack formal role (`ret 0x10` vs three decomp formals).  
3. Nested spawn ctor identities beyond size/role.  
4. Runtime / bit-diff.

---

## 7. Verdict

**accept-with-gaps** — ABI, return, strings, range default, stream/version spine, and map inserts sealed; field atlas residual does not block structural port.
