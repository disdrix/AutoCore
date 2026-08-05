# Dual A/B report — W24-Q OWN-ONLY (`aa_004f4eb0`, `aa_00814400`)

**Date:** 2026-07-29  
**Agent:** W24-Q OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004f4eb0`, `0x00814400`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004f4eb0` Vehicle_DeactivateHardpointWeapons_Inferred | **accept-with-gaps** — thiscall vehicle*; 3-slot `+0x260` clear fire+suppress + `vtbl+0x18(0)`; sole caller vehicle-switch; ret sealed |
| `aa_00814400` Client_RecvObjectResolveWeaponReset_0x201c_Inferred | **accept-with-gaps** — S2C **0x201C**; resolve/create/update; optional weapon clear + FireHelper(suppress=1); EDI/EBX dispatch ABI sealed |

---

## Sealed facts — `0x004f4eb0`

1. **Body:** `0x004f4eb0`–`0x004f4efe` (**78 B** exclusive end).

2. **ABI:** **thiscall/fastcall** vehicle* in **ECX**; **0** stack args; plain **`ret`**.

3. **Table:** `*(vehicle+0x260)` → pointer table; loop offsets **0,4,8** bound **0xC** (3 hardpoints).

4. **Per non-null weapon:** `Weapon_SetFireFlagPair(0)` → `Weapon_SetSuppressFlag_Cb(0)` → `vtbl+0x18(0)`.

5. **Caller:** sole `FUN_005252f0` @ `0x0052556b` with `ECX = *(session+0x250)`.

6. **Sibling (not owned):** `FUN_004f4f00` activate twin.

7. **Name:** `Vehicle_DeactivateHardpointWeapons_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_004f4eb0`.

---

## Sealed facts — `0x00814400`

1. **Body:** `0x00814400`–`0x00814466` (**102 B** exclusive end).

2. **Wire:** S2C opcode **`0x201C`** via `Client_PacketDispatch` (sole xref).

3. **ABI:** dispatch-custom **EDI**=packet*, **EBX**=game*; plain **`ret`**.

4. **Resolve:** `CVOGReaction_ResolveObjectTarget` with type `packet+0x98`, ids `+0x90/+0x94`, this=`*(game+0xD34)`.

5. **Branch:** null → `FUN_008120d0` create; else `FUN_00811e00` sector-update.

6. **Weapon tail:** if `obj->vtbl[+0x1E0]()` non-null → clear fire pair + `Weapon_FireHelper(&DAT_00d1a680, 1)` (suppress).

7. **Name:** `Client_RecvObjectResolveWeaponReset_0x201c_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00814400`.

---

## Gaps

### `004f4eb0`
1. Product English for hardpoint `vtbl+0x18`.  
2. Exact C++ type for session+0x250 vehicle host.  
3. Runtime vehicle-switch differential — open.  
4. Activate sibling full seal — not OWN.

### `00814400`
1. Product English for opcode 0x201C / packet struct.  
2. Full nested create/update (`FUN_008120d0` / `FUN_00811e00`) — not OWN.  
3. `vtbl+0x1E0` product (which weapon) and `DAT_00d1a680` role.  
4. Runtime wire capture differential — open.

---

## Files

### `aa_004f4eb0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004f4eb0_FUN_004f4eb0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_DeactivateHardpointWeapons_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004f4eb0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.annotated.md` |

### `aa_00814400`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00814400_FUN_00814400.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvObjectResolveWeaponReset_0x201c_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00814400.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00814400_FUN_00814400.md` |
| Annotated | `docs/reconstruction/raw/aa_00814400_FUN_00814400.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004f4eb0-00814400-w24q-report.md` |

---

## AutoCore impact

### `004f4eb0`
- On vehicle switch / inventory handoff, clear fire+suppress on all **3** hardpoints under `vehicle+0x260` and run deactivate presentation vfunc(0).
- Do not reuse fire-all (`0x004f50d0`) logic for this path.
- Server ports can clear authoritative fire-intent without client vfunc if presentation-only.

### `00814400`
- Route S2C **0x201C** to resolve-or-create object, then **reset weapon fire state** (clear flags + suppress FireHelper) — **not** a shoot command.
- Preserve packet fields `+0x90/+0x94/+0x98` for identity resolve.
- Distinct from `0x201A` resolve-only sibling.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
