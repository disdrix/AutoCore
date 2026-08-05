# Review A (reconstruction fidelity): `aa_004b99c0` NDSpecialFX_TeardownCore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b99c0` |
| **VA** | `0x004b99c0` |
| **Canonical name (Ghidra)** | `FUN_004b99c0` |
| **Proposed name** | `NDSpecialFX_TeardownCore_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004b99c0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX lifetime |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Core teardown body for an NDSpecialFX object (~`0x240`)** before heap free. Used heavily by load/parse failure paths, `NDSpecialFX_LoadFromScriptName`, weapon/FX free sites, and catalog flush in `FUN_004a6390` (`LoadMasterFromXML`).

Sequence (dword indices on `uint *this`):

| Step | Action |
|---|---|
| 1 | If `this[0xF]` (`+0x3C`) non-null → `operator_delete`; then zero |
| 2 | If `this[0x18]` (`+0x60`) non-null → `operator_delete`; then zero |
| 3 | `FUN_004b85d0(this)` — clear child intrusive lists (`+0x1E0`, `+0x204`, `+0x210`, `+0x1EC`, `+0x1F8`, map `@+0x228`, …) |
| 4 | If `*this & 1` → `FUN_005875c0(&this)` unlink from external registry list; clear bit 0 |
| 5 | `FUN_004bacf0` range-clear on map rooted at `this[0x8A]` (`+0x228`) |
| 6 | `operator_delete(this[0x8A])` — free map header (decompiler ends here; see gaps) |

**Not** the full C++ scalar deleting dtor alone (callers typically `004b99c0` then `operator_delete(fx)`), and **not** a play/activate helper.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004b99c0` |
| Function meta | body `004b99c0`–`004b9a5c` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004b99c0` |
| Function record | `docs/reconstruction/functions/aa_004b99c0_FUN_004b99c0.md` |
| Sibling | `A_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` (calls `004b85d0` + this + delete) |
| List clearer | live `FUN_004b85d0` decompile |
| Map clearer | live `FUN_004bacf0` decompile |

**This pass:** live decompile; 34 xrefs; callee roles. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// ECX = NDSpecialFX*
void __fastcall NDSpecialFX_TeardownCore_Inferred(void *fx /* ECX */);
```

SEH frame present (`LAB_009a15f7`, `local_4` state 8→7). Ghidra marks several `operator_delete` sites **noreturn** — known false; control continues after frees (same artifact as LoadFromScriptName dual).

---

## 4. Callers (sample of 27+) / callees

| Callee | Role |
|---|---|
| `operator_delete` | Free owned blocks at `+0x3C`, `+0x60`, map header `+0x228` |
| `FUN_004b85d0` | Child list / audio / param teardown |
| `FUN_005875c0` | Unlink host from intrusive registry when bit0 set |
| `FUN_004bacf0` | Map node range destroy helper |

High-traffic callers include: `NDSpecialFX_LoadFromScriptName`, `FUN_004a6390`, `FUN_004a2670`, weapon fire helpers `FUN_0056a9e0` / `FUN_0056d020`, many `0051xxxx` / `005a8xxx` free paths.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Free/zero `+0x3C` | Yes |
| Free/zero `+0x60` | Yes |
| `004b85d0` | Yes |
| Bit0 unlink + mask | Yes |
| Map clear `+0x228` + delete header | Yes (decompiler ends at final delete) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| NDSpecialFX teardown / pre-delete body | **High** | Layout peers `+0x1E0..+0x228`; LoadFromScriptName uses it |
| Offsets `+0x3C` / `+0x60` owned heap | **High** | explicit delete + zero |
| `+0x228` = map header (`this[0x8A]`) | **High** | `004bacf0` + delete; `004a0b90` walks same map |
| Bit0 = “registered in external list” | **Probable** | `005875c0` list remove by pointer match |
| Decompiler cut after last delete | **High** artifact | body ends `004b9a5c`; no further high-level steps expected |
| Product dtor name / vtbl slot | **Tentative** | `_Inferred` |
| Whether `004b85d0` must be called before this (double-clear) | **Probable safe** | LoadFromScriptName calls both; `004b85d0` empties lists |

---

## 7. Gaps / open

1. Exact product destructor name / whether this is the whole dtor or a shared helper.
2. Type of heap objects at `+0x3C` and `+0x60` (param pack / secondary host — sibling of `004b68c0` layout notes).
3. Full `005875c0` registry owner object (thiscall lost).
4. Runtime leak/no-double-free verification not run.

**Verdict:** **accept-with-gaps** — teardown CF High; product naming + owned-pointer types open.
