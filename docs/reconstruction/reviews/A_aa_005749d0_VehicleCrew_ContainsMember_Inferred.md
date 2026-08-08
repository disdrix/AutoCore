# Review A (reconstruction fidelity): `aa_005749d0` VehicleCrew_ContainsMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005749d0` |
| **VA** | `0x005749d0` |
| **Body end** | exclusive `0x00574a2e` (94 B); pad `CC` |
| **Canonical name** | `VehicleCrew_ContainsMember_Inferred` |
| **Ghidra name** | `FUN_005749d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9R-A OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/table layout/callers sealed; product English open |

---

## 1. Purpose

**Four-slot crew roster membership test.** Returns true if the candidate object's COID lo/hi pair matches any slot at `this+0x198` (stride `0x10`).

```c
// __thiscall RET 4; AL bool
bool VehicleCrew_ContainsMember_Inferred(CrewHost* this, void* candidate);
```

Not faction math, not TFID full-16 compare, not vehicle identity alone (callers also use `vtbl+0x210` same-vehicle).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.md` (+ re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_ContainsMember_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005749d0.cpp` |
| Live Ghidra | `decompile_function 0x005749d0`; `analyze_function_complete`; `read_memory`; callers |
| Mode 0xb context | `FUN_0058a810`; gather dual `a_0058d330.md` |
| Filter consumer | `Skill_FilterTargetForResolveList_Inferred` |
| Twin writer | `FUN_005755b0` |

**Live re-decompile + epilogue bytes + mode-0xb call site performed.** No `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x005749d0`–`0x00574a2e` excl. | **Confirmed** | function bounds + pad |
| `__thiscall` + `RET 4` | **Confirmed** | `C2 04 00` both exits |
| Null candidate → 0 | **Confirmed** | early `test eax,eax` / `xor al,al` |
| COID via offBase+0x164/0x168 | **Confirmed** | `mov esi,[edx+eax+0x164]` etc. |
| 4 slots × stride `0x10` @ `+0x198` | **Confirmed** | loop `cmp dl,4` / `jb`; offsets `0x198/0x19c` |
| Return AL 0/1 (not CONCAT31) | **Confirmed** | `32 C0` / `B0 01` epilogues |
| Leaf (no callees) | **Confirmed** | analyze complete |
| 8 named callers / 14 xrefs | **Confirmed** | callers + xrefs |
| Mode 0xb uses `vehicle+0xCB0` as this | **Confirmed** | `mov ecx,[edi+0xCB0]` before call |
| Product C++ name | **Inferred** | no string/RTTI |

---

## 4. Control flow

```
if candidate == null → false
load coidLo/Hi from candidate via SharedBase offBase (+0x164/+0x168)
for slot = 0..3:
  if this[0x198+slot*0x10] == coidLo && this[0x19c+slot*0x10] == coidHi → true
return false
```

### Mode 0xb (gather helper `FUN_0058a810`)

```
casterVeh = caster.vtbl+0x210()
candVeh   = candidate.vtbl+0x210()
if casterVeh == 0 → reject
if casterVeh == candVeh → accept          // same vehicle
if casterVeh+0xCB0 == 0 → reject
if VehicleCrew_ContainsMember(crewHost=*(veh+0xCB0), candVeh) → accept
else reject
```

Self allowed in gather body for mode `0xb` (documented in `Skill_GatherTargetsInArea` dual).

---

## 5. Gaps (acceptable)

1. Product English / MSVC demangle for crew-host class.
2. Whether slots always store vehicle COIDs vs character COIDs (callers pass both shapes).
3. Remaining 8 bytes of each 0x10 slot (writer stores object* at `(slot+0x1A)*0x10`).
4. Runtime / bit-exact / differential (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| Bool return sealed over decompiler noise | **Pass** |
| Table layout sealed | **Pass** |
| Mode 0xb this-pointer sealed | **Pass** |
| Clean meaningful names | **Pass** |
| Verdict | **accept-with-gaps** |
