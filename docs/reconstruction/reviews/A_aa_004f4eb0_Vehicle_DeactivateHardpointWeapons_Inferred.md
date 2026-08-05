# Review A (reconstruction fidelity): `aa_004f4eb0` Vehicle_DeactivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4eb0` |
| **VA** | `0x004f4eb0`–`0x004f4efe` |
| **Canonical name** | `Vehicle_DeactivateHardpointWeapons_Inferred` |
| **Ghidra symbol** | `FUN_004f4eb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| **System** | `combat` / vehicle hardpoint weapons |
| **Verdict** | **accept-with-gaps** — ABI + 3-slot clear/deactivate loop sealed; vfunc+0x18 product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` body + call-site `read_memory` @ `0x00525560` + callers/xrefs. No `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

Vehicle **hardpoint weapon deactivation** helper:

1. Load hardpoint table from **`this+0x260`**.
2. For slot offsets `0,4,8` (bound **`0xC`** = 3 pointers): if weapon non-null, clear fire-flag pair, clear suppress flag, call **`vtbl+0x18(0)`**.
3. Return.

Used when switching vehicles (`FUN_005252f0` — "switched vehicles…" string path) so outgoing/current vehicle hardpoints do not keep fire/suppress state.

**Sibling (not owned):** `FUN_004f4f00` walks the same table and **activates** (`vtbl+0x18(1)` / full activate path) after fire clear.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.md` (+ W24-Q append) |
| Annotated | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_DeactivateHardpointWeapons_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004f4eb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| Live decompile | Ghidra `0x004f4eb0` — **≡** raw body |
| Live bytes | `read_memory` len 80 @ entry |
| Call site | `0x00525560`: `mov ecx,[esi+0x250]; call 0x004f4eb0` |
| Sibling context (not owned) | `FUN_004f4f00`, `Weapon_SetFireFlagPair`, `Weapon_SetSuppressFlag_Cb` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **thiscall/fastcall**: vehicle* in **ECX** (`8B F9`) |
| Stack args | **none**; epilogue plain **`C3` ret** |
| Return | void |
| Body | `0x004f4eb0`–`0x004f4efe` (78 B); `CC` pad after |
| Callees | `0x0056a260`, `0x0056b400`, indirect `vtbl+0x18` |

### 3.2 Loop + callees — **SEALED**

| Fact | Evidence |
|---|---|
| Table base | `[this+0x260]` |
| Slots | esi=0,4,8 while esi < **0xC** |
| Per slot | null-skip; `SetFireFlagPair(0)`; `SetSuppressFlag(0)`; `vtbl+0x18(0)` |
| Caller ECX | `*(session+0x250)` at `0x00525566` |

### 3.3 Name — **INFERRED**

`Vehicle_DeactivateHardpointWeapons_Inferred` — role sealed from CF + sibling activate twin + hardpoint duals. Product C++ name open.

---

## 4. Confidence table

| Claim | Confidence |
|---|---|
| Bytes / CF / ret | **High** |
| 3 hardpoints at +0x260 | **High** |
| Clear fire + suppress before vfunc(0) | **High** |
| Vehicle this from +0x250 | **High** |
| Deactivate English for vtbl+0x18 | **Medium** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps**
