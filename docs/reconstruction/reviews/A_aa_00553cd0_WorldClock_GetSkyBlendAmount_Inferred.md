# Review A (reconstruction fidelity): `aa_00553cd0` WorldClock_GetSkyBlendAmount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553cd0` |
| **VA** | `0x00553cd0`–`0x00553cd6` inclusive (**7 B**) |
| **Canonical name (Ghidra)** | `FUN_00553cd0` |
| **Proposed name** | `WorldClock_GetSkyBlendAmount_Inferred` |
| **Review date** | `2026-08-04` (WQ9F-J OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` |
| **System** | environment / world clock / sky blend |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **getter** on the same world-clock host as dualed `WorldClock_GetQuarterPhase01_Inferred` (`0x00553dd0`). Loads **`*(float*)(this+0x15c)`** onto **x87 ST0**. Sole consumer is env day-cycle tick `FUN_004912c0`, which feeds the value as **`fBlendAmount`** into skybox material updates (`FUN_00490af0` / `"fBlendAmount"` / SkyBox family strings).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x00553cd0` |
| Bytes | `read_memory` — `D9 81 5C 01 00 00 C3` (`fld [ecx+0x15c]; ret`) + `CC` pad |
| Body meta | `get_function_by_address` — body `00553cd0`–`00553cd6` |
| Callers | sole `FUN_004912c0` @ `0x004912e5` (`xref_count=1`) |
| Sibling | dualed `WorldClock_GetQuarterPhase01_Inferred` @ `0x00553dd0` (same host; different field) |
| Consumer use | live decompile `FUN_004912c0` → `FUN_00490af0(local_4,…)` with `"fBlendAmount"` / `"SkyBox*"` |
| Raw / annotated / clean | `docs/reconstruction/*` for `aa_00553cd0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
float __fastcall WorldClock_GetSkyBlendAmount_Inferred(void *clock /*ECX*/);
// bare ret (C3); result on x87 ST0 (fld [ecx+0x15c])
```

| Item | Evidence |
|---|---|
| ECX this | `fld dword ptr [ecx+0x15c]` — no stack args |
| Offset | `5C 01 00 00` = **+0x15c** |
| Return | x87 ST0; decompiler `float10` |
| Epilogue | bare **`C3`** |
| Size | **7 B** exclusive pad; next `FUN_00553ce0` @ `0x00553ce0` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Single load `this+0x15c` | Yes |
| Bare ret / no callees | Yes |
| Sole env caller | Yes (`FUN_004912c0`) |
| Consumer → sky `fBlendAmount` | Yes (caller chain, not in this leaf) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body = `fld [ecx+0x15c]; ret` | **Confirmed** | bytes |
| Same clock host as quarter-phase getter | **High** | sibling dual + shared caller |
| Sole static consumer env tick | **Confirmed** | 1 xref |
| Role: stored float used as sky blend amount | **High** | consumer `"fBlendAmount"` + SkyBox strings |
| Product field / PDB English | **Tentative** | `_Inferred` |
| Writers of `+0x15c` | **Open** | not OWN |

---

## 6. Gaps / open

1. Product/PDB symbol for clock class and field.  
2. Who writes `+0x15c` (init / network / designer default).  
3. Whether blend is always sky-only or multi-consumer in live play (static xrefs: one).  
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — ABI/bytes/role High; product English open.
