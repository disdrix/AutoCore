# Review B (skeptical / adversarial): `aa_0058d8e0` Skill_HB_ApplyMultiArgEffect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d8e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; product name residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **is** multi-hit core (merge with `0058c850`) | Body is 126 B wrapper; sole CALL to `0058c850`; no accuracy/damage loop | **Falsified as merge** — distinct thin wrapper |
| 2 | This is heat/HP/shield Apply* sibling (`00589bc0`/`00589c70`/`00589d90`) | No float scale; builds TFID list; calls multi-hit | **Falsified** |
| 3 | This is short+floater (`0058cc40`) | Different callee; list-build present | **Falsified** |
| 4 | `thiscall` / `ret 4` | Bare `ret` (`c3`); no ECX this use; callers `ADD ESP,0x18` | **Falsified** — **cdecl** |
| 5 | Target gather / world query | No area/mode args; copies existing object TFID only | **Falsified** |
| 6 | Multi-entry list from object field array | Exactly one 16 B entry + terminator; no loop | **Falsified as multi-entry builder** — single-entry list |
| 7 | `param_2+0x160` is position/matrix/float4 | Parent multi-hit / floater duals treat `+0x160` as TFID; terminator is null TFID pattern | **Falsified as pos/matrix** — TFID role survives |
| 8 | Decompiler `void` means no return value | Multi-hit returns int total; sites `0061e92a`/`0061ea83` store EAX then FILD | **Survives as int damage return** |
| 9 | `Named_CalleeOf_*` / scaffold is product name | Generic machine name only; role name supersedes | **Superseded** by `Skill_HB_ApplyMultiArgEffect_Inferred` |
| 10 | Always runs on every HB tick | Parent `TEST [ESI+0x648],1` gate before call | **Falsified as unconditional** |
| 11 | `param_4` is required damage field | Multi-hit dual sealed `param_4` unused | **Survives as unused forward** |
| 12 | Terminator is zeros only | `read_memory` @ `009d4d28` = `ffffffff ffffffff 00000000 00000000` | **Sealed** non-zero lo/hi |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 6 / bare ret / 126 B | **High** | Wrong port ABI |
| +0x160 TFID + null terminator list | **High** | Wrong list shape to multi-hit |
| Sole callee multi-hit apply | **High** | Port as wrong subsystem |
| HB cascade leaf under shared pulse | **High** | Misplace in skill graph |
| Product symbol | **Open** | Doc only |
| param_1 vs param_2 English (source/hittee) | **Probable** | Wrong AutoCore binding |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0058d8e0  mov  eax, [esp+8]        ; param_2
0058d8e4  sub  esp, 0x20
0058d8e7  test eax, eax
0058d8e9  jnz  0058d8ef
0058d8eb  add  esp, 0x20
0058d8ee  ret                      ; early
0058d8ef  add  eax, 0x160
… four dword copy to [esp] …
… four dword terminator from DAT_009d4d28.. …
… six pushes; call 0058c850; add esp,18; add esp,20; ret
```

Live 2026-08-05 ≡ 2026-07-23 raw decompile CF. Entry hex:

```
8b442408 83ec20 85c0 7504 83c420 c3 0560010000 ...
```

---

## 4. Parent misuse check

Parent `FUN_0061b6f0` decompiler collapses the 6-arg call into a fake `FUN_00578270(...); FUN_0058d8e0(uVar5)` single-arg form. Adversarial reading: is the multi-arg packing decompiler fiction?

Counter via assembly at `0x0061b8f9`:

1. Six explicit pushes before CALL.  
2. `FUN_00578270` is thiscall-only (`mov ecx,esi; call`) — resolves reaction object into EAX.  
3. Post-call `ADD ESP,0x18` seals 6 dwords.  
4. Sibling heat path really is 1-arg; multi-arg path is the **only** 6-arg arm.

Decompiler arg-merge **falsified**; live pack **sealed**.

---

## 5. Surviving contract for AutoCore

```
if (object == null) return 0;
tfidList = { object.tfid16_at_0x160, NullTfid };
return Skill_ApplyMultiTargetHits(
    combatSource, tfidList, damageBlob, unused4, rollTable, rollSeed);
```

Port as **cdecl** wrapper, not thiscall. Do not inline multi-hit logic here. Keep distinct from heat/HP/shield/short-floater Apply* leaves. Gate remains parent's bit0@`+0x648`.

**Verdict:** **accept-with-gaps**.
