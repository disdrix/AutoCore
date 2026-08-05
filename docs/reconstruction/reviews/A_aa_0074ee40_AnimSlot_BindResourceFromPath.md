# Review A (reconstruction fidelity): `aa_0074ee40` AnimSlot_BindResourceFromPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ee40` |
| **VA** | `0x0074ee40`–`0x0074eea9` |
| **Canonical name** | `AnimSlot_BindResourceFromPath` |
| **Ghidra name** | `FUN_0074ee40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-S) |
| **Counterpart** | `reviews/B_aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| **System** | client::anim / ND resource |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`); parent `Object_LoadOrReplaceAnimSlot` W18-C |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind a path-keyed ND resource onto a **0x78 anim slot**:

1. `typeDesc = FUN_00449070()` (lazy type singleton).
2. `res = NDResourceCache_LookupOrCreate(DAT_00d1f050, path, typeDesc, 0, 0)`.
3. Store `res` at **`this+0x70`**; fail → **`-1`**.
4. Call resource **`vtbl+4`** → ready char.
5. `inner = NDResource_AcquireInnerObject(res)`; store **`this+0x74`**; null → **`-1`**.
6. `FUN_00963950(inner)` channel extract; **`-1`** → fail.
7. `FUN_0074eaa0()` weight/duration init.
8. Return **`(ready != 0)`** as 0/1.

Parent loaders (`Object_LoadOrReplaceAnimSlot`) treat **`result >= 0`** as success.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_BindResourceFromPath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074ee40.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| Parent dual | `Object_LoadOrReplaceAnimSlot` (`0x005828b0`, W18-C) |
| Live | decompile ≡ 2026-07-23 raw; `read_memory` 106 B; epilogue `C2 04 00` ×2 |

---

## 3. Signature (sealed)

```c
// ECX = AnimSlot*; stack pathKey; return uint; RET 4
uint32_t AnimSlot_BindResourceFromPath(AnimSlot *self, void *pathKey);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX → ESI | **High** |
| pathKey | Stack[0x4] | **High** |
| cleanup | `RET 4` (both paths) | **High** |
| fail | `0xFFFFFFFF` | **High** |
| success | 0 or 1 from vtbl+4 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
typeDesc = FUN_00449070()
res = CacheLookupOrCreate(DAT_00d1f050, path, typeDesc, 0, 0)
this+0x70 = res
if !res → -1
ready = res.vtbl[+4]()
inner = AcquireInner(res); this+0x74 = inner
if !inner → -1
if FUN_00963950(inner) == -1 → -1
FUN_0074eaa0()
return (ready != 0)
```

| Stage | Match | Conf |
|---|---|---|
| thiscall + ret 4 | **Yes** | **High** |
| Cache lookup + store +0x70 | **Yes** | **High** |
| vtbl+4 ready flag | **Yes** | **High** |
| Acquire + store +0x74 | **Yes** | **High** |
| Channel extract gate | **Yes** | **High** |
| Weight init before success ret | **Yes** | **High** |
| Parent uses `result >= 0` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body @ `0x0074ee40`: prologue `56 57 8B F1`; `DAT_00d1f050` load `8B 0D 50 F0 D1 00`; stores `89 46 70` / `89 46 74`; fail `83 C8 FF`; epilogues `C2 04 00`.

---

## 6. Gaps

- Product English for ND resource / anim asset type.
- Full meaning of pathKey (string vs handle from `FUN_00989e00`).
- Nested helper duals (cache, acquire, extract, weight init) residual.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/slot offsets sealed; product English + nested helpers residual.
