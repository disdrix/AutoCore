# Review A (reconstruction fidelity): `aa_0093e120` Client_SelectTargetObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093e120` |
| **VA** | `0x0093e120`–`0x0093e3b2` |
| **Canonical name** | `Client_SelectTargetObject_Inferred` (Ghidra `FUN_0093e120`; prior Named plate `Named_CalleeOf_Client_Input_PollBoundActions_0093e120`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093e120_Client_SelectTargetObject_Inferred.md` |
| **System** | `interaction-activation` / client target selection (also called from input poll / click pick) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / bulk xrefs / callers. Prefer decompile/`read_memory`. Own VA only. No ledgers.

---

## 1. Purpose

Central **client select-target** applicator for object pointer `param_1` (may be null to clear):

1. Optional **context-menu / interaction host** notify (`client+0xf38→+0xcc0` vfuncs) when pick has component flag `…+0x4f9≠0` and host not already locked to same target.
2. Load character `client+0xe98`; early **return** if `char+0x4f1≠0` (busy / suppress select).
3. If `char+0xd78==0`: if vehicle at `char+0x250`, call **`FUN_004f3700`** (empty drive-path NoOp) — **no** `SetHandbrake` in this arm; then `Object_SetSelectedTarget` on character component chain.
4. Else if `char+0x6b9≠0` and alternate host at component `+0xa4`, same `Object_SetSelectedTarget` join.
5. Refresh several UI panels if visible (`+0x10a4`, `+0x10b4`, `+0x10a0` → `FUN_008b2470` / `FUN_00893580` / `FUN_008e9690`).
6. First-time tips 4 and maybe 9 when target valid / level gap ≥2.
7. **Highlight chrome:** if `client+0x3048` selection display ≠ `param_1`, clear old (`vfunc+0x17c`, mask `+0x184`, zero `+0x118`), light new (`vfunc+0x178` with ones), store `param_1` at `+0x3048`, clear `+0x304c/+0x3050`.

**Registers:** `unaff_ESI` = client; `param_1` stack object*; live decompile also shows `unaff_EDI` into `Object_SetSelectedTarget` (third arg / context). Annotated raw historically named `FUN_005172d0` for the select helper — live symbol **`Object_SetSelectedTarget`**.

**Entry bytes:** `sub esp,0x10; push ebx/ebp; mov ebp,[esp+0x1c]` (stack `param_1`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0093e120_*`, `reconstructed-exact/FUN_0093e120.cpp` (+ Named) |
| Function record | `functions/aa_0093e120_FUN_0093e120.md` |
| Live decompile | CF + renamed `Object_SetSelectedTarget` |
| Xrefs | **27** unconditional call sites |
| Named callers | `Client_InteractClickPickTarget`, `Client_Input_PollBoundActions`, `Client_Input_OnKeyDown_MatchAction`, `FUN_00921f70`, `FUN_00925820`, others |

**Not performed:** dual of every UI refresh callee; runtime pick capture; full English for all 27 sites.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Primary role = apply selection + chrome | **High** | many pick/poll callers + `+0x3048` store |
| Early abort on `char+0x4f1` | **High** | return before select |
| DrivePathNoOp when vehicle non-null (no HB) | **High** | live decompile; contrast `00915670`/`0093a5c0` |
| `Object_SetSelectedTarget` on allow path | **High** | live name; raw `FUN_005172d0` same call |
| Highlight swap at `client+0x3048` | **High** | clear/set block always reachable at end (if char null, jumps to LAB still runs chrome) |
| First-time tips 4 / 9 | **High** | callees named |
| 27 call sites | **High** | bulk xrefs |
| Product English for every UI panel FUN | **Open** | residual |
| Full third-arg ABI of SetSelectedTarget | **Probable** | live shows `unaff_EDI` |
| Runtime | **Open** | deferred |

---

## 4. Control flow skeleton

```
// optional interaction-host notify (flag +0x4f9 path)

char = *(client+0xe98)
if !char: goto highlight
if *(u8*)(char+0x4f1): return          // hard abort — no highlight update

if *(u8*)(char+0xd78)==0:
  if *(char+0x250): DrivePathNoOp(vehicle)
  Object_SetSelectedTarget(char_component, param_1, ctx)
else if *(u8*)(char+0x6b9) && host@+0xa4:
  Object_SetSelectedTarget(host, param_1, ctx)

// UI panel refreshes if visible
// first-time tips if param_1 valid

highlight:
  if client.selChrome(+0x3048) != param_1:
    clear old; light new; store param_1
```

---

## 5. Callers (named subset)

| Caller | Role context |
|---|---|
| `Client_InteractClickPickTarget` | click pick → select (and sometimes UseObject separately) |
| `Client_Input_PollBoundActions` | bound-action select |
| `Client_Input_OnKeyDown_MatchAction` | key path select |
| `FUN_00925820` / `FUN_00921f70` / UI `FUN_00943*` / net `FUN_008*` | other select entry points |

Full 27 sites in live xrefs — English residual for unnamed FUN_*.

---

## 6. Gaps / open

1. Product name (leave `_Inferred`).
2. Exact semantics of `char+0x4f1`, `+0xd78`, `+0x6b9`.
3. Why select path calls empty `FUN_004f3700` without HB (shared empty notify — open intent).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — select CF, suppress return, NoOp-without-HB, chrome store, tip calls, 27-site graph sealed; field English / runtime open.
