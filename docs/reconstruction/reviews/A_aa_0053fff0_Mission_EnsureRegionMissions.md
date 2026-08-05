# Review A (reconstruction fidelity): `aa_0053fff0` Mission_EnsureRegionMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053fff0` |
| **VA** | `0x0053fff0` |
| **Canonical name** | `Mission_EnsureRegionMissions` |
| **Review date** | `2026-07-29` (wave3 seal: `+0xf18` wrapper) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live decompile + bytes) |
| **Counterpart** | `reviews/B_aa_0053fff0_Mission_EnsureRegionMissions.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept** — getter + wrapper layout sealed; secondary index keys residual |

---

## 1. Purpose

MSVC `__fastcall` / thiscall-style lazy getter:

1. `ECX = owner` (common live site: `DAT_00b041fc`; NpcMissionDialog: `*(clientCtx+0xd30)`).
2. If `*(owner + 0xf18) == 0`:
   - `operator_new(0x10)`
   - if non-null: `ECX = block` → `FUN_0060b870` (`Mission_VOGRegionMissions` / `CVOGRegionMissions` ctor)
   - else treat as null
   - store result at `owner+0xf18`
3. Return `*(owner + 0xf18)` — a **wrapper\*** (0x10 object), **not** the primary hash.

Callers that need the mission-id table must **`*wrapper`** (or equivalent) before `CNDHash_LookupByKey` / traverse / lock `hash+0x1d`.

**Sibling (not this unit):** `FUN_0053ff80` @ `0x0053ff80` — same lazy path + optional `FUN_0056e4e0`, **void** (ensure only).

---

## 2. Inspected artifacts / evidence

| Source | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` / `batch_decompile` `0x0053fff0`, `0x0060b870`, `0x0053b0b0`, `0x0053b1b0`, `0x0060c010`, `0x0053c360`, `0x0053c460` (2026-07-29) |
| Live bytes | Ghidra `read_memory` `0x0053fff0` (SEH + `cmp [esi+0xf18]`, `push 0x10`, `call new`, `mov ecx,eax` / `call 0x0060b870`, store) |
| Raw | `docs/reconstruction/raw/aa_0053fff0_FUN_0053fff0.md` |
| Annotated | `docs/reconstruction/raw/aa_0053fff0_FUN_0053fff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053fff0.cpp` / `Mission_EnsureRegionMissions.cpp` |
| Ctor record | `docs/reconstruction/functions/aa_0060b870_FUN_0060b870.md` |
| Callers | Ghidra `get_function_callers` / `get_function_xrefs` |
| Cross duals | SearchAutoMissions, HasCompletedMission, CompleteMissionObjectives, GiveMission |

---

## 3. Seal: getter body

```c
// __fastcall ECX = owner
void* Mission_EnsureRegionMissions(void* owner)
{
  if (*(void**)((char*)owner + 0xf18) == 0) {
    void* p = operator_new(0x10);
    void* w = p ? Mission_VOGRegionMissions_ctor(p) /* FUN_0060b870 */ : 0;
    *(void**)((char*)owner + 0xf18) = w;
  }
  return *(void**)((char*)owner + 0xf18);
}
```

| Claim | Confidence | Evidence |
|---|---|---|
| Slot offset **`+0xf18`** | **High** | Live decompile + `cmp dword [esi+0xF18]` bytes |
| Alloc size **`0x10`** | **High** | `push 0x10` / `operator_new(0x10)` |
| Ctor `FUN_0060b870` on success | **High** | `mov ecx,eax; call 0x0060b870` |
| OOM → store **null** | **High** | `xor eax,eax` path |
| Return is slot contents (wrapper\*) | **High** | final `mov eax,[esi+0xf18]` |
| Does **not** return `*wrapper` | **High** | body has no second deref; callers deref |

---

## 4. Seal: `+0xf18` wrapper (`CVOGRegionMissions` / 0x10)

Ctor product evidence (`FUN_0060b870`):

- Log path: `C:\vog\1_code\vog_14_117_branch\libVOG\VOGRegionMissions.cpp` line `0x33`
- OOM: `"Out-o-memory... missions!"`
- Prior alias: `Mission_VOGRegionMissions`

### 4.1 Layout (four `void*` at `wrapper+0x00..+0x0C`)

| Off | Index | Construction | Role (sealed) | Conf |
|---|---|---|---|---|
| `+0x0` | `[0]` | `operator_new(0x34)` + `FUN_0053b0b0(8)` — vtbl `PTR_FUN_009cfa4c` | **Primary mission-id CNDHash** (mask bits=8 → 256). Callers: `hash = *wrapper`. Insert path: `FUN_0053c360(key=*def, value=def)` | **High** |
| `+0x4` | `[1]` | `operator_new(0x34)` + `FUN_0053b1b0(8)` — vtbl `PTR_FUN_009cfa58` | **Secondary CNDHash** (same size/mask; distinct vtbl). Per-def objective loop inserts via `FUN_0053c460(key=obj+0x10, value=obj)` | **High** layout; **Probable** “objective-by-id” product gloss |
| `+0x8` | `[2]` | `operator_new(0x38)` + `FUN_0053b0b0(8)` then vtbl→`PTR_FUN_009df688`, dword `[0xd]/`+0x34` = 0 | Extended hash (0x38) | **High** shape; **index key residual** |
| `+0xC` | `[3]` | same as `[2]` | Extended hash (0x38) | **High** shape; **index key residual** |

Null any of the four → log OOM + `VOG_DEBUG_STOP` (does not necessarily abort after log).

### 4.2 Population (ctor, for wrapper seal context)

| Path | When | Steps |
|---|---|---|
| **Preload vector** | `DAT_00b0434c != 0` and `(DAT_00b04350-DAT_00b0434c)>>2 > 0` | Use existing def pointers from vector (WAD/clonebase fill; see `CloneBase_LoadWadFile`) |
| **DB cold load** | vector empty | `FUN_007e1d80` → `FUN_007c0350` (`Mission_DbLoadQuestsAndObjectives`) → `FUN_007b7df0`; per row `FUN_005480d0(...,1)` then free COM buffers |

Per mission def after hash construction:

1. Insert into primary `[0]` by `*def` (mission id).
2. If `def[0x22]` (`+0x88`) != `-1`: `FUN_0060c010(key=def[+0x88], value=def)` (this = one of the secondary tables — **this-ptr residual** in decompile).
3. `FUN_0060c010(key=byte def[+0x86], value=def)`.
4. For each objective in def byte-count `@+0x130` (`(char)def[0x4c]`), insert into `[1]` via `FUN_0053c460`.

---

## 5. Callers (Ghidra; ownership stays here only for getter semantics)

Named / high-signal:

| Caller | VA |
|---|---|
| `CVOGReaction_GiveMission` | `0x005327c0` |
| `CVOGCharacter_SearchAutoMissions` | `0x00532b60` (×4) |
| `CVOGCharacter_HasCompletedMission` | `0x0052aa20` |
| `CVOGCharacter_CompleteMissionObjectives` | `0x00536080` |
| `CVOGCharacter_CheckMissionPrerequisites` | `0x00536540` |
| `CVOGReaction_CompleteObjective` | `0x00533f90` |
| `CVOGCharacter_ApplyCreateFromPacket` | `0x00534bd0` |
| `CVOGObject_EvalOfferableMissionInteractState` | `0x004d5aa0` |
| `CVOGObject_EvalInteractStateFromChildren` | `0x004d7640` |
| `Client_RecvNpcMissionDialog` | `0x00815070` |
| `Client_ShowNpcMissionDialogUI` | `0x009438f0` |
| `Client_UpdateMissionJournal` | `0x008ae130` |
| `CVOGVariable_EvaluateComputed` | `0x005afd40` |

Plus residual `FUN_*` sites (`0x004d2e50`, `0x004d4040`, `0x004d5c10`, `0x0052c9d0`, `0x0052cca0`, `0x00536740`, `0x005aa8f0`, `0x008a4900`, `0x008ec750`, `0x008ecf40`, `0x009572e0`, …).

**Typical ECX:** `DAT_00b041fc` (global owner; image-static null until runtime fill). Dialog path: `*(pClientCtx+0xd30)`.

---

## 6. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH frame + null-check `+0xf18` | **Yes** |
| `new(0x10)` → ctor or 0 → store | **Yes** |
| Return slot | **Yes** |
| No extra deref / no populate in getter | **Yes** |

---

## 7. Gaps (unit-local residuals)

1. Product English method name beyond role (`Ensure` / `Get` / `GetOrCreate`) — class **High** via `VOGRegionMissions.cpp`.
2. Owner type of `DAT_00b041fc` / `ctx+0xd30` product name.
3. Exact `this` for `FUN_0060c010` (which of `[2]`/`[3]`/other) and product meaning of keys `def+0x88` / `def+0x86`.
4. Extended hash vtbl `PTR_FUN_009df688` product type.
5. Sibling `FUN_0053ff80` / `FUN_0056e4e0` relationship (out of unit).

**Verdict:** **accept** for getter + primary wrapper layout; secondary index semantics open.
