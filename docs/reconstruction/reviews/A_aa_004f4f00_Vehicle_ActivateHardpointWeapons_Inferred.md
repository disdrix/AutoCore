# Review A (reconstruction fidelity): `aa_004f4f00` Vehicle_ActivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4f00` |
| **VA** | `0x004f4f00`–`0x004f4faa` (171 B) |
| **Canonical name** | `Vehicle_ActivateHardpointWeapons_Inferred` |
| **Ghidra symbol** | `FUN_004f4f00` |
| **Review date** | `2026-07-29` (W25-E dual seal) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004f4f00_Vehicle_ActivateHardpointWeapons_Inferred.md` |
| **System** | combat / vehicle hardpoint weapons |
| **Verdict** | **accept-with-gaps** — ABI + 3-slot activate loop + fire-clear sealed; vfunc product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` body + call-site `read_memory` @ `0x005259ad` + callers/xrefs. **No** `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

Vehicle **hardpoint weapon activation** helper (post fire-clear):

1. Load hardpoint table from **`this+0x260`**.
2. For slot offsets `0,4,8` (bound **`0xC`** = 3 pointers): if weapon non-null, clear fire-flag pair, then:
   - if `weapon[+0x08]==0`: full **`vtbl[0](1, 0×6, g_flOne, 0)`**
   - else: **`vtbl+0x18(1)`**
3. Return.

Used when switching vehicles (`FUN_005252f0` / `Character_SwitchVehicle_Inferred`) so the bound vehicle hardpoints enter active state after deactivate twin ran earlier in the same switch.

**Twin:** `Vehicle_DeactivateHardpointWeapons_Inferred` @ `0x004f4eb0` (W24-Q) — same table; fire+suppress clear; `vtbl+0x18(0)` only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f4f00_FUN_004f4f00.md` (+ W25-E append) |
| Annotated | `docs/reconstruction/raw/aa_004f4f00_FUN_004f4f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_ActivateHardpointWeapons_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004f4f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f4f00_FUN_004f4f00.md` |
| Live decompile | Ghidra `0x004f4f00` — **≡** raw body |
| Live bytes | `read_memory` len 176 @ entry (171 body + CC pad) |
| Call site | `0x005259ad`: `mov ecx,[esi+0x250]; call 0x004f4f00` |
| Twin context | `aa_004f4eb0` dual (W24-Q); `Weapon_SetFireFlagPair` dual |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **thiscall/fastcall**: vehicle* in **ECX** (`8B F9`) |
| Stack args | **none**; epilogue `add esp,0x10; ret` (locals) |
| Return | void |
| Body | `0x004f4f00`–`0x004f4faa` (**171 B**); `CC` pad after |
| Callees | `0x0056a260`, indirect `vtbl[0]` / `vtbl+0x18` |

### 3.2 Loop + callees — **SEALED**

| Fact | Evidence |
|---|---|
| Table base | `[this+0x260]` |
| Slots | esi=0,4,8 while esi < **0xC** |
| Per slot | null-skip; `SetFireFlagPair(0)`; branch on `[w+8]`; activate **1** |
| g_flOne | `0x00a0f2a0` = `1.0f` (`read_memory`) |
| No suppress clear | no call to `0056b400` (unlike deactivate twin) |
| Caller ECX | `*(character+0x250)` at `0x005259ad` |

### 3.3 Name — **INFERRED**

`Vehicle_ActivateHardpointWeapons_Inferred` — role sealed from CF + deactivate twin polarity + hardpoint duals. Product C++ name open.

---

## 4. Confidence table

| Claim | Confidence |
|---|---|
| Bytes / CF / ret | **High** |
| 3 hardpoints at +0x260 | **High** |
| Fire clear then activate(1) | **High** |
| Twin of deactivate | **High** |
| vtbl product English | **Medium** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps**
