# Review A (reconstruction fidelity): `aa_00943520` Client_SelectNearestHostileInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943520` |
| **VA** | `0x00943520`–`0x009436bb` (**411** bytes) |
| **Canonical name** | `Client_SelectNearestHostileInRange_Inferred` |
| **Prior scaffold** | `FUN_00943520` / `Named_CalleeOf_Client_Input_PollBoundActions_00943520` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — live Ghidra WQ9R-D) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` |
| **System** | skills-abilities / client target pick |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `get_function_xrefs` / `read_memory`. **No** `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

**Nearest-hostile select within stack range → apply selection:**

1. **ABI:** `this` in **EAX** (client host); stack **float rangeArg**; **`RET 4`**. Prologue `MOV ESI,EAX`.
2. **Gate:** `char = *(client+0xe98)`; if `*(u8*)(char+0x4f1) != 0` → return (busy suppress shared with `Client_SelectTargetObject`).
3. **Origin:** MI adjust char → `vtbl+0x1a0()` float4 position copy.
4. **Seed** out TFID from `g_abTfidInvalid_A15870` (`0x00a15870`).
5. **Gather pass 1:** `Skill_GatherTargetsInArea` with **maxTargets=1**, **mode=2 (hostile)**, filterA=0, chain=0, allowSelf=1, filterB=0, filterC=1, **sortByDistance=1**, scoreArg=−1.0f; range = stack arg; source = char MI; queryArg = `*(char_comp+0xa8)`.
6. If still invalid TFID → **pass 2** identical except **sortByDistance=0**.
7. If still invalid → return (no select / no clear).
8. Else: `ECX = *(*(char_comp+0xa8)+0xe4e8)`; `Object_ResolveFromTFID(&tfid)`; if non-null → `Client_SelectTargetObject_Inferred(obj)`.

### PollBound context

Three sites in `Client_Input_PollBoundActions` push **`0x42dc0000` (110.0f)** and `MOV EAX, DAT_00d1a840`:

| Edge keys | Behavior |
|---|---|
| `DAT_00d1beca/becb` (or binder `DAT_00d1b624(2)`) | if `DAT_00d1d888==0` → this unit; else `FUN_00943340(110, 0)` cycle prev |
| `DAT_00d1be96/be97` | if `DAT_00d1d888==0` → this unit; else `FUN_00943340(110, 1)` cycle next |
| `DAT_00d1befe/beff` | always this unit (nearest) |

Fourth CODE xref `0x00925467` (no containing function in Ghidra) uses same range/client pattern.

**Not** screen-ray hostile pick (`Client_SelectHostileUnderScreenPick`), not multi-target cycle body (`FUN_00943340`), not gather implementation.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` @ `0x00943520` |
| Body range | `get_function_by_address` → `00943520`–`009436bb` |
| Body bytes | `read_memory` 420 B (full body + pad) |
| Invalid bank | `read_memory` `0x00a15870` → `FF×8 00×8` |
| Xrefs | 4 CODE sites |
| Callees | GatherTargets / Object_ResolveFromTFID / SelectTargetObject (rel32 sealed to `004bb950`, `0093e120`) |
| Sibling duals | `Skill_GatherTargetsInArea` mode table; `Client_SelectTargetObject_Inferred`; `Client_SelectHostileUnderScreenPick` |
| Raw / annotated / clean | `aa_00943520_*`, `Client_SelectNearestHostileInRange_Inferred.cpp` |

**Not performed:** Launcher, runtime keybind capture, dual of `FUN_00943340` (owned by WQ9R-C), product bind strings.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 411 B, `RET 4` | **High** | exit `C2 04 00` |
| EAX-this ABI | **High** | prologue `8B F0`; call sites `B8 40 A8 D1 00` |
| Busy gate `+0x4f1` | **High** | decompile + bytes |
| Mode 2 / max1 / sort 1 then 0 | **High** | push literals `6A 02` / `6A 01` / sort `6A 01` then `6A 00` |
| scoreArg −1.0f | **High** | `68 00 00 80 BF` |
| Invalid TFID test | **High** | `AND` lo/hi + `bGlobal==0` |
| Resolve + select path | **High** | rel32 → `004bb950`, `0093e120` |
| Poll range 110.0f | **High** | caller `68 00 00 DC 42` |
| Product keybind English | **Open** | edge DAT_* only |
| `*(char+0xa8)` product type | **Probable** | queryArg / host with `+0xe4e8` resolve tables |
| Runtime | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Busy gate early out | **Yes** |
| Position vtbl+0x1a0 | **Yes** |
| Invalid seed | **Yes** |
| Gather sort=1 then optional sort=0 | **Yes** |
| Double-invalid → return | **Yes** |
| Resolve ctx + SelectTarget | **Yes** |
| No select(0) clear arm | **Yes** (unlike screen-pick sibling) |

---

## 5. Gaps / open

1. Product/PDB / input-binding names for the three edge DAT pairs.
2. Precise product type of `*(char_comp+0xa8)` (query host).
3. Why allowSelfMode1=1 on mode 2 (mode table: self ignored for mode 2 — likely harmless literal).
4. Orphan xref `0x00925467` function boundary.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — nearest hostile CF, literals, ABI, resolve/select path sealed; product bind names open.
