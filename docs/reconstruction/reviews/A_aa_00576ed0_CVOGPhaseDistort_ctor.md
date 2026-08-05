# Review A (reconstruction fidelity): `aa_00576ed0` CVOGPhaseDistort_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576ed0` |
| **VA** | `0x00576ed0`–`0x00576f11` exclusive (**65 B** / `0x41`) |
| **Canonical name** | `CVOGPhaseDistort_ctor` |
| **Prior scaffold** | `FUN_00576ed0` |
| **Review date** | `2026-07-29` (W32-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00576ed0_CVOGPhaseDistort_ctor.md` |
| **System** | client / VOGEnvironmentSector phases |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `get_function_by_address` + `get_function_xrefs` + `get_bulk_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Complete ctor of process-singleton **`CVOGPhaseDistort`** (size **0x18**): store view, install class vtbl, zero piece-list tails.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` @ `0x00576ed0` ≡ 2026-07-23 raw CF |
| Bytes | `read_memory` — SEH `LAB_009a514a`; `c700 c03b9d00`; zero +0xC/10/14; **`C2 04 00`** |
| Bounds | `get_function_by_address` body `00576ed0`–`00576f10` (Ghidra); exclusive end **`00576f11`** via pad `CC` |
| RTTI | vtbl[-1] COL `0x00aaed0c` → type_info `0x00af31a0` → **`.?AVCVOGPhaseDistort@@`** |
| Caller | sole CODE `0x0048fd60` in `FUN_0048fc90` — `new(0x18)` + view@`+0xC0` → `DAT_00b04818` |
| Related | dtor `00576f20`; init `00576d70`; plate method `00576f70` |
| Raw / clean | `aa_00576ed0_*`, `CVOGPhaseDistort_ctor.cpp` |

**Not performed:** Launcher, runtime construct, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 65 B / `ret 4` / returns this | **Confirmed** | bytes + EAX=this |
| thiscall + 1 stack arg (view) | **Confirmed** | `ret 4`; factory push |
| Vtbl / RTTI `CVOGPhaseDistort` | **Confirmed** | COL chain |
| Layout +0x04 view; zero +0x0C..+0x14 | **Confirmed** | decompile ≡ bytes |
| Sole factory + alloc 0x18 + singleton globals | **Confirmed** | W31-P peer + xrefs |
| Field English for tails / `+0x08` | **Open** | |
| Runtime / differential | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// SEH LAB_009a514a
self[+0x04] = view;
*self = &PTR_FUN_009d3bc0;
self[+0x0C]=self[+0x10]=self[+0x14]=0;
return self; // ret 4
```

| Stage | Match |
|---|---|
| SEH + store view before/with vtbl | Yes |
| Zero three dwords | Yes |
| ret 4 | Yes |

---

## 5. Gaps / open

1. Product English for piece-instance field tails (`+0x08` untouched by ctor).
2. Runtime / bit-exact / differential.

**Verdict:** **accept** — sealed CF, ABI, RTTI class, sole factory path.
