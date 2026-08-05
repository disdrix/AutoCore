# Review A (reconstruction fidelity): `aa_005252f0` Character_SwitchVehicle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005252f0` |
| **VA** | `0x005252f0`–`0x00525a92` (1955 B) |
| **Canonical name** | `Character_SwitchVehicle_Inferred` |
| **Ghidra symbol** | `FUN_005252f0` |
| **Review date** | `2026-07-29` (W25-E dual seal) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005252f0_Character_SwitchVehicle_Inferred.md` |
| **System** | vehicle / inventory-transfer / client chassis switch |
| **Verdict** | **accept-with-gaps** — ABI + HRESULT + stage CF + nested hardpoint duals sealed; product name + many nested helpers residual |

**Tools:** Ghidra `decompile_function` + `read_memory` (entry/epilogue/call sites) + `analyze_function_complete` + callers. **No** `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

Client **character vehicle chassis switch**:

1. Reject null new vehicle (`E_INVALIDARG`).
2. Optionally write old vehicle (`character+0x250`) to out-param.
3. If new cargo pages (`vehicle+0x1e6`) **<** old pages: temporary inventory grid + RePlaceItems migrate; fail → `E_FAIL`.
4. Snapshot transforms; flag objects; **deactivate** old hardpoints (`004f4eb0`).
5. Create cargo on new vehicle; mark old `+0x2ac=1`.
6. If new lacks chassis phys (`+0x258`): alloc/init 0x2F0 object; optional 64-bit id bump when args are `0xFFFFFFFF`; `Vehicle_SetWheelset`.
7. Rebind pose/flags/nested objects; write 0.25f constant; **activate** hardpoints (`004f4f00`).
8. Stow old vehicle via dual inventory-fit; on total failure log switched-vehicles + `VOG_DEBUG_STOP`.
9. Return `S_OK` (0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005252f0_FUN_005252f0.md` (+ W25-E append) |
| Annotated | `docs/reconstruction/raw/aa_005252f0_FUN_005252f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SwitchVehicle_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005252f0.cpp` |
| Function records | `functions/aa_005252f0_*.md` |
| Live decompile | Ghidra `0x005252f0` — **≡** raw body CF |
| Live bytes | prologue @ entry; epilogue `C2 10 00` @ `0x00525a90` |
| Call site | `0x00810490`: push pair + out + new; `mov ecx,[esi+0xe98]; call` |
| Nested duals | `004f4eb0` (W24-Q), `004f4f00` (W25-E owned), `004f3a30` cargo |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **thiscall** ECX=character (`8B F1`); stack new/out/a/b |
| Cleanup | **`RET 0x10`** (4 stack dwords) |
| Returns | `0`, `0x80070057`, `0x80004005` (bytes + decompile) |
| Body size | **1955 B** (`0x7A3`); exclusive end `0x00525a93` |
| Callers | `00810360`, `0093d880` (2 xrefs) |

### 3.2 Stage CF — **SEALED (high-level)**

Guard → out-old → cargo shrink → snapshot/flag → deactivate hardpoints → new cargo → optional phys/wheelset → rebind → activate hardpoints → stow old → S_OK.

### 3.3 Nested hardpoint pair — **SEALED**

| Call | VA | Role |
|---|---|---|
| `FUN_004f4eb0` | mid-switch | deactivate old |
| `FUN_004f4f00` | late-switch | activate (W25-E) |

### 3.4 Name — **INFERRED**

`Character_SwitchVehicle_Inferred` — ECX is character (`client+0xe98`), not vehicle; string + callers seal switch role. Product C++ name open.

---

## 4. Confidence table

| Claim | Confidence |
|---|---|
| ABI / HRESULT / body size | **High** |
| Stage order + cargo page compare | **High** |
| Hardpoint deactivate/activate pair | **High** |
| `+0x1e6` pages / `+0x2ac` gate / `+0x260` table | **High** (cross-dual) |
| argA/argB English | **Medium** (sentinel `0xFFFFFFFF` path High) |
| Full nested helper duals | **Residual** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps**
