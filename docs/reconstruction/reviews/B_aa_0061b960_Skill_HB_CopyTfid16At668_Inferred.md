# Review B (skeptical / adversarial): `aa_0061b960` Skill_HB_CopyTfid16At668_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/offset/role; product name residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function returns a **pointer into** the skill object (field getter) | Bytes: dest is stack arg; four stores to `*out`; EAX=out at entry | **Falsified** — out-copy |
| 2 | Source is float4 / color / matrix row @ +0x668 | Width 16 B; parent expands to 4 dword args for target `vtbl+0x88` after identity resolve | **Falsified as float/color** — identity blob role survives |
| 3 | `cdecl` / no stack cleanup | `ret 4` | **Falsified** — thiscall + 1 arg |
| 4 | Mutates skill-HB TFID | Only loads from this after `add ecx,0x668` | **Falsified** |
| 5 | Same as `Object_CopyTfid16At228` (same VA / offset) | Different entry `0x0061b960`, offset `0x668` vs `0x228` | **Falsified as merge** — twin shape, distinct unit |
| 6 | Multi-caller general object helper | Sole xref: `FUN_0061b6f0` @ `0x0061b760` | **Falsified as multi-caller** — skill-HB local leaf |
| 7 | Decompiler `void` means EAX unused | EAX = out at entry and preserved; post-call uses `[eax]` | **Survives as return=out** |
| 8 | Offset is +0x660 / +0x670 (nearby field slip) | Bytes `add ecx, 0x668` | **Offset sealed 0x668** |
| 9 | Scaffold `Named_CalleeOf_*` is product name | Generic leaf; role name supersedes | **Superseded** by `Skill_HB_CopyTfid16At668_Inferred` |
| 10 | Writes heat/HP/shield (sibling Apply* confusion) | Body is pure copy; no call to `00589bc0`/`00589c70`/etc. | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x668 / 16 B / ret 4 | **High** | Wrong skill-HB layout |
| TFID role | **High** | Confuse with pos/matrix/color |
| Skill-HB `this` (not world object) | **High** | Port to wrong class |
| Product symbol | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0061b960  mov  eax, [esp+4]           ; out
0061b964  add  ecx, 0x668
0061b96a  push esi
0061b96b  mov  esi, [ecx]
0061b96d  mov  edx, eax
0061b96f  mov  [edx], esi
… three more dword pairs …
0061b983  pop  esi
0061b984  ret  4
```

Live 2026-08-05 ≡ 2026-07-23 raw decompile CF. Hex:

```
8b442404 81c168060000 56 8b31 8bd0 8932 8b7104 897204 8b7108 897208 8b490c 894a0c 5e c20400 cc
```

---

## 4. Parent misuse check

Parent `FUN_0061b6f0` decompile shows:

```c
puVar4 = (undefined4 *)FUN_0061b960(auStack_10);
(**(code **)(*piVar3 + 0x88))(scaledShort, *puVar4, puVar4[1], puVar4[2], puVar4[3]);
```

Adversarial reading: could `puVar4` be a float vector? Counter: (1) exact 16 B TFID twin shape; (2) args are four raw dwords after a scaled short damage/period; (3) target obtained via `vtbl+0x214` identity resolve path. TFID-out-copy claim **survives**.

---

## 5. Surviving contract for AutoCore

```
out = Skill_HB_CopyTfid16At668(skillHbWithTfidAt668);
// out is 16 B; parent expands to 4 dword args for target apply
```

Do not invent server-side mutation; leaf copy only. Keep distinct from `Object_CopyTfid16At228_Inferred` (`+0x228`).

**Verdict:** **accept**.
