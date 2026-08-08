# Function record: Item_GetTinkerSkillOrCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521eb0` |
| **Canonical name** | `Item_GetTinkerSkillOrCap_Inferred` (**Inferred** — product field English open) |
| **Ghidra name** | `FUN_00521eb0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0` (**retired**) |
| **Rejected misname** | `Character_GetTinkerSkillOrCap` as ECX=character (call sites pass **item**) |
| **Address** | `0x00521eb0`–`0x00521ef6` inclusive (**71 B** / `0x47`) |
| **Jump table** | data `0x00521ef8`–`0x00521f1b` (9× dword) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / tinker kit |
| **Parent dual / context** | partition parent `0x00513c10` (Item_ValidateTinkerKitUse hint); sibling caller `0x00521f20` |
| **Agent** | MEGA-106 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Map item byte **`+0x59b`** to a **capped skill-tier / cap value 0..5** used in tinkering gates:

```text
v = item[+0x59b]
if v == 0: return 0
if v in 1..9: return (v+1)/2   // pairs: 1-2→1 … 9→5
if v >= 10: return 5
```

Parents compare `return` against **character** `vfunc(+0x8c) + 1` to accept/reject tinker operations (and, in `FUN_00521f20`, to gate a float formula that also re-reads raw `+0x59b`).

## Signature

```c
// __thiscall: ECX = item; no stack args; EAX = uint8 tier 0..5; plain RET
std::uint8_t __thiscall Item_GetTinkerSkillOrCap_Inferred(void *item);
```

## Layout (item fields touched)

| Offset | Width | Role in this VA |
|---|---|---|
| **+0x59b** | u8 | **read** — source rank/tier byte |
| +0x6b4 | i32 | not read here; parents gate on it |

## Call graph

| Role | Target |
|---|---|
| **Callers (2 sites)** | `FUN_00513c10` @ `0x00513ca4` (`MOV ECX,EDI` item); `FUN_00521f20` @ `0x00521f59` (`MOV ECX,EDI` item this) |
| Callees | **none** (leaf) |
| Xrefs | 2 UNCONDITIONAL_CALL |

## Chain context (not dualled; evidence only)

```text
FUN_00513c10  Item_ValidateTinkerKitUse (partition hint)  [residual / parent]
  ├─ character vfunc +0x8c  → skill S
  ├─ FUN_00521eb0  Item_GetTinkerSkillOrCap_Inferred  [OWN MEGA-106]  // ECX=item
  └─ compare tier vs S+1; item+0x6b4 special-case

FUN_00521f20  tinker float helper  [residual]
  ├─ character vfunc +0x8c  → skill S
  ├─ FUN_00521eb0  [OWN MEGA-106]
  └─ if tier >= S+1: float from raw +0x59b + peer +0xb0
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Item_GetTinkerSkillOrCap_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00521eb0.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0.cpp`
- Raw: `docs/reconstruction/raw/aa_00521eb0_FUN_00521eb0.md`
- Annotated: `docs/reconstruction/raw/aa_00521eb0_FUN_00521eb0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00521eb0_FUN_00521eb0.md`
- Report: `docs/agents/task-dual-ab-00521eb0-mega-106-report.md`

## Confidence

| Claim | Level |
|---|---|
| Switch CF + jump table targets | **Confirmed** |
| ECX=item; +0x59b; plain RET; EAX tier | **Confirmed** |
| Mapping table / cap 5 | **Confirmed** |
| Tinker / inventory-transfer role via callers | **High** |
| Product English for +0x59b / skill name | **Inferred** |
| Runtime Confirmed | **Open** |
