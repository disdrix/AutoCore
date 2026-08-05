# Review A (reconstruction fidelity): `aa_0096e8e0` EffTextureFactory_ReCreateDefaultPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e8e0` |
| **VA** | `0x0096e8e0`–`0x0096e9e4` exclusive (**260 B**) |
| **Canonical name** | `EffTextureFactory_ReCreateDefaultPool_Inferred` |
| **Ghidra name** | `FUN_0096e8e0` |
| **Prior scaffold** | `FUN_0096e8e0` / `Named_effTextureFactory_0096e8e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-AB) |
| **Counterpart** | `reviews/B_aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md` |
| **System** | palantir graphics Effects — effTextureFactory |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + sole-caller call-site + strings. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Texture-factory half of device reset: rebuild every DEFAULT-pool effect texture on the factory list after the device has been Reset.

1. Walk circular list head at `factory+0x8`.
2. For each impl with `+0x30 == 0`: recreate via `FUN_0096cad0` unless `(flags & 0x3000)` → Release `+0x4c` only.
3. On `hr < 0`: log `effTextureFactory.cpp:0x159` `"Failure on ReCreate() of effTextureImpl %s at <%x>"` and return.

**Not** create-from-file, not full factory dtor, not the pre-reset release walk (that calls `FUN_0096c8e0` from Reset directly).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0096e8e0` (2026-08-04) ≡ raw scaffold |
| Bytes | `read_memory` — full **260 B**; SEH; epilogue **`C2 04 00`** |
| Parent | `GfxDevice_Reset` live decompile + call-site `0x0075f2bb`: `push [device+0x754]; call; test eax` |
| Strings | failure plate + `effTextureFactory.cpp` / line `0x159` |
| Callees | `FUN_0096cad0`, `FUN_0096a630`, `FUN_0076cec0`, `vog_LogMessage`, IAT dtor, vtbl[+8] |
| Pair | `FUN_0096c8e0` (create first-step release) |
| Raw / annotated / clean | `aa_0096e8e0_*`, named + twin cleans |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// stack factory*; RET 0x04; returns hr
int EffTextureFactory_ReCreateDefaultPool_Inferred(EffTextureFactory* factory);
```

| Formal | Source | Conf |
|---|---|---|
| factory* | stack0 (`mov eax,[esp+0x10]` after SEH prolog) | **Confirmed** |
| RET 4 | `C2 04 00` | **Confirmed** |
| return hr | `mov eax,edi` (last recreate result / 0) | **Confirmed** |

Parent: `push factory; call` — not thiscall.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| SEH `LAB_009b09a1` | **Yes** | **Confirmed** |
| List walk head `+0x8` circular | **Yes** | **Confirmed** |
| Gate `impl+0x30 == 0` | **Yes** | **Confirmed** |
| Flags `0x3000` → Release `+0x4c` else `FUN_0096cad0` | **Yes** | **Confirmed** |
| Fail: a630 + format + log line 0x159 + return | **Yes** | **Confirmed** |
| Body 260 B / pad to `0096e9f0` | **Yes** | **Confirmed** |

### DEFAULT-pool gate

Same `+0x30 == 0` test used by Reset **before** device Reset to call `FUN_0096c8e0` on each lost texture. After successful device Reset, this VA rebuilds those entries.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack factory / RET 4 / hr | **Confirmed** | bytes + sole caller |
| ReCreate DEFAULT-pool list | **Confirmed** | strings + CF |
| Create via `FUN_0096cad0` | **Confirmed** | call + thiscall site |
| Source file/line plate | **Confirmed** | embedded string |
| Flag `0x3000` / `+0x4c` product role | **Open** | structural only |
| Nested create dual | **Open** | not owned |
| Product demangle | **Open** | `_Inferred` |
| Runtime | **Open** | |

---

## 6. Gaps (explicit)

- Product/MSVC demangle.
- Full meaning of `0x3000` branch and `+0x4c` interface.
- Dual for `FUN_0096cad0` / list shell type / `FUN_0096a630`.
- Exact `FUN_0096cad0` stack formal order under Ghidra thiscall noise (port from call-site bytes when dualing create).
- Runtime under live device Reset.

---

## 7. Verdict rationale

ABI, list walk, DEFAULT gate, recreate/fail CF, and product source plate are sealed. Nested create dual and flag product English open → **accept-with-gaps**.
