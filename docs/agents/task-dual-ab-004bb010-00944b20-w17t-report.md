# Dual A/B report — W17-T OWN `0x004bb010` + `0x00944b20`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x004bb010`, `0x00944b20`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004bb010` `Object_ResolveTfIdVtbl1d4_Inferred` | **accept-with-gaps** — resolve + `vtbl+0x1d4` + ECX passthrough sealed; product vtbl name open |
| `aa_00944b20` `Client_TeardownGameplaySession_Inferred` | **accept-with-gaps** — EAX-this ABI + full/partial CF sealed; nested product names open |

---

## `0x004bb010` — Object_ResolveTfIdVtbl1d4_Inferred

### Sealed facts

1. **Body** `0x004bb010`–`0x004bb039`; **42 B**; leaf-thin wrapper.
2. **ABI:** stack blob* cleaned by **`RET 4`**; **ECX = resolve context** supplied by caller and preserved into `CVOGReaction_ResolveObjectTarget` (`0x004bae70`). Decompiler omits ECX (same trap as `Object_ResolveFromTFID`).
3. **Algorithm:** unpack blob `+0` coidLo, `+4` coidHi, `+8` bGlobal → Resolve → if null return 0 else **`obj->vtbl[+0x1d4]()`**.
4. **Bytes ≡ decompile**  
   `8b4424048b5004528b108a40085250e84cfeffff85c0740d8b108bc8ff92d4010000c2040033c0c20400`.
5. **Callers (5):** `Client_CreateVehicleObjectApply`, `ClientSpecialEvent_Respawn_Update`, `ClientSpecialEvent_Respawn_dtor`, `FUN_00979290`, `FUN_00979310`.
6. **CreateVehicle:** `FUN_004bb010(pkt+0x90)` is the existing-object gate; ctx often `host+0xe4e8`.
7. **Siblings:** `004bb950` resolve-only; `004bb070` `+0x1d8` GetIdentity; `004bb0a0` `+0x1dc` Lookup.

### Gaps

1. Product name of `vtbl+0x1d4`.  
2. Whether return is always identity-equal to resolved `obj`.  
3. Runtime / bit-exact / image diff.  
4. Exhaustive per-caller ECX provenance (only CreateVehicle site bytes sealed).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004bb010_FUN_004bb010.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1d4_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004bb010.cpp` |
| Raw | `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.md` |
| Annotated | `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.annotated.md` |
| Scratch | `tmp/a_004bb010.md` |

---

## `0x00944b20` — Client_TeardownGameplaySession_Inferred

### Sealed facts

1. **Body** `0x00944b20`–`0x00944d03`.
2. **ABI:** **this in EAX** (not ECX); stack **`char fullTeardown`**; **`RET 4`**. Prologue `MOV ESI,EAX`.
3. **Call sites:** `PUSH 1; MOV EAX, 0x00d1a840; CALL/JMP` — global client main.
4. **`fullTeardown != 0`:** five UI COM slots (`+0x309c/+0x30a8/+0x30a4/+0x30ac/+0x30b0`) with flag pairs and `vtbl+4(0)` Release; audio/mission helpers; optional `+0x31ec` path; zero **`0x82` dwords** at `+0x31f0` then `*buf = -1`; map/UI zero helpers.
5. **Always:** `delete[] +0xf44`; clear `+0x113`/`+0x134`; `FUN_008076c0`; conditional leave on `+0xf40`/`+0xf38` match and `DAT_00d1b77c`.
6. **Callers:** login fail (`RecvPlayFail`), `RecvAccountKicked` (forces flag=1 via stack rewrite + tail JMP), auth return-to-login, missing-region content abort in reinitPhysics.
7. **17 callees** listed in function record (not dual-owned here).

### Gaps

1. Product names of five UI COM objects and most nested callees.  
2. Existence of live `fullTeardown=0` path.  
3. Types of `+0x31f0` buffer and `+0xf40`/`+0xf38` pair.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00944b20_FUN_00944b20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_TeardownGameplaySession_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00944b20.cpp` |
| Raw | `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.md` |
| Annotated | `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.annotated.md` |
| Scratch | `tmp/a_00944b20.md` |

---

## AutoCore impact

- **CreateVehicle / ghost path:** existing-object detection is **not** a bare TFID hash hit — it is resolve + **`vtbl+0x1d4`**. Ports that only call `Object_ResolveFromTFID` may diverge if `+0x1d4` unwraps.
- **Session leave / login fail:** client teardown is a multi-stage orchestrator with a **full vs light** flag; server ports need not mirror UI COM releases, but should understand client always clears `+0xf44` and session gates.
- Do not merge this unit with `AuthClient_SendLogout` — different layer.

---

## This report

`docs/agents/task-dual-ab-004bb010-00944b20-w17t-report.md`
