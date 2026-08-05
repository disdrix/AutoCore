# Review A (reconstruction fidelity): `aa_00862860` Client_ItemMatchesActiveHardpointMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862860` |
| **VA** | `0x00862860` |
| **Body** | `0x00862860`–`0x008629a1` (322 bytes) |
| **Canonical name** | `Client_ItemMatchesActiveHardpointMode_Inferred` |
| **Ghidra name** | `FUN_00862860` |
| **Review date** | `2026-07-29` (W18-O dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` |
| **System** | inventory-transfer / hardpoint equip UI |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Predicate: does **item** (ECX) fit the **currently active hardpoint/equip UI mode** from **uiHost** (ESI `vtbl+0x3cc`)? Used to gate hardpoint drop and equip UI selection.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00862860_FUN_00862860.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00862860_FUN_00862860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ItemMatchesActiveHardpointMode_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00862860.cpp` |
| Function record | `docs/reconstruction/functions/aa_00862860_FUN_00862860.md` |
| Live decompile | `0x00862860` |
| Bytes | body 322 B; jmp table `0x008629a4`; byte map `0x008629c0` |
| Call sites | Drop hardpoint `0x00863469`, UI click `0x0086384f`, `FUN_00862b70` |
| Class map peer | `Client_RecvInventoryEquip` hardpoint switch |

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| ECX=item*, null→false | **Confirmed** | prologue `test ecx,ecx`; callers `mov ecx,ebx/edi` |
| ESI=uiHost, `vtbl+0x3cc` mode | **Confirmed** | callers set ESI; many `call [reg+0x3cc]` |
| `item+0xA8` → cloneBase; `+0x38` class | **High** | decompile `param_1[0x2a]+0x38`; equip family |
| Jump table + byte map | **Confirmed** | `read_memory` @ `0x008629a4` / `0x008629c0` |
| Class set 6/10/0xc/0xe/0x10/0x1c | **Confirmed** | switch cases + map |
| Mode constants 1–9, 0xd | **Confirmed** | `cmp` immediates in handlers |
| Class labels plant/wheel/armor/weapon | **High** | peer equip dual (not product string here) |
| Product function / mode enum names | **Open** | INFERRED |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null item → false | **Yes** |
| Class switch / default false | **Yes** |
| Ornament subtypes 10 / 0xb → modes 9 / 8 | **Yes** |
| Weapon nested subtype/flags → 7/4/5/6 | **Yes** |
| Plant/wheel/armor/0xe modes | **Yes** |
| Invented classes | **None** |

---

## 5. Gaps

1. Product name of helper and `vtbl+0x3cc`.
2. Product labels for mode integers (UI tab vs hardpoint index).
3. Weapon `+0x536` flag bit product meanings.
4. Runtime / differential — open.

**Verdict:** **accept-with-gaps**
