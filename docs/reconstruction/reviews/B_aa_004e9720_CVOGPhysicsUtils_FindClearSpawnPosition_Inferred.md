# Review B (skeptical / adversarial): `aa_004e9720` CVOGPhysicsUtils_FindClearSpawnPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-027 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is only `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_*` | scaffold alias | **Falsified as sole role** — also called by CreateTemplateVehicle + 2 other FUN_*; body is generic sphere clear-placement probe |
| 2 | Is the query-collect ctor (`005eb790`) | partition parent merge | **Falsified** — **calls** parent then runs collect loop; body 892 B vs ctor ~49 B |
| 3 | Is sphere shape ctor (`006c7fa0`) | callee merge | **Falsified** — different VA; this unit allocates then calls shape ctor |
| 4 | Is `CVOGPhysicsUtils::FindDistanceToTarget` (`004e9aa0`) | adjacent util | **Falsified** — different VA; that unit returns float10 distance with product string; this returns bool placement |
| 5 | Is `GetObjectsInArea` / sphere collect path | family bleed | **Falsified** — no area-list return; out is single float4; success = zero hits |
| 6 | thiscall / RET n / ECX=self | convention noise | **Falsified** — frame + bare **`RET`**; callers **`ADD ESP,0x20`** |
| 7 | `param_1` unused / dead | decompiler formals | **Falsified** — asm uses host for `+0xE4A4` and height thiscall |
| 8 | Returns void / undefined | analyze `return_type undefined` | **Falsified** — `SETZ BL; MOV AL,BL`; callers `TEST AL,AL` |
| 9 | Success means "hit found" | invert bool | **Falsified** — empty collect count → success; callers fail on AL==0 with "Couldn't find a spawn position" |
| 10 | Product method name sealed (drop `_Inferred`) | family wishful | **Fails (open)** — no plate/string DATA xref in body |
| 11 | Runtime Confirmed | wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | Always restores original position on fail | restore path | **Falsified** — restore only when still-blocked **and** `param_8 == 0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl bare RET / 8 stack args / bool AL | **High** | Corrupt every call site |
| Sphere probe + clear-placement loop | **High** | Wrong spawn pipeline |
| Distinct from parent ctor / shape / FindDistance | **High** | Merge wrong types |
| Host physics register @ `+0xE4A4` | **High** | Wrong host field |
| Product `CVOGPhysicsUtils` method English | **Med** | Doc only (`_Inferred`) |
| `param_6` cookie English | **Low–Med** | Filter semantics only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
host   = [EBP+0x8]
in     = [EBP+0xC]   // float4*
scatter= [EBP+0x10]  // param_3
radius = [EBP+0x14]  // param_4 sphere + Y pad
out    = [EBP+0x18]  // float4*
cookie = [EBP+0x1C]  // into query-params
tries  = [EBP+0x20]  // uchar countdown
keep   = [EBP+0x24]  // uchar; 0 → restore in on total fail

shape = alloc(0x10, tag 0x22); PhysicsShape_Sphere_CtorFromRadius(shape, radius)
params = stack block; FUN_005eb8d0(params); params.cookie = cookie; params.shape = shape; copy in float4
query = alloc(0xD0, tag 0x2C); VOGPhysics_QueryCollect_Ctor(query, params)   // parent 005eb790
release shape refcount
FUN_0055ff20(*(host+0xE4A4), query)                                       // register
hit = { vtbl=009ccbb4, count=0, cap=0x80000010, buf=stack }
*out = *in; out.y += radius + 0.5f
found_clear = true  // "still_blocked" inverted: bVar3 starts true=blocked-seeking
do:
  FUN_005eb130(query, out)
  vcall(query, +0x30)(&hit)
  if hit.count == 0:
    found_clear = true; tries = 0   // success path (decomp: bVar3=false)
  else:
    clear hit; u1,u2 = random_ushort×2
    *out = *in
    out.x += (u2 * scale - 1.0f) * scatter
    out.z += (u1 * scale - 1.0f) * scatter
    out.y  = height(host, out.x, out.z) + radius + 0.5f   // FUN_004cd220 thiscall host
  tries--
while tries was non-zero (JA)
if still_blocked && keep==0: *out = *in
FUN_00560020(*(host+0xE4A4), query); release query; FUN_004eacc0(hit); free shape heap
return found_clear
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_005eb790` — query-collect **ctor** (parent dual R12-037); this unit **consumes** it.
* `FUN_006c7fa0` — sphere **shape** ctor (MEGA-071).
* `FUN_004e9aa0` — `CVOGPhysicsUtils::FindDistanceToTarget` (product string); distance, not placement.
* `FUN_004ea350` — `GetObjectsInArea` (uses sphere-collect sibling `005ebec0`, not this path).
* Scaffold `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720` — parent-seed plate only; **retire**.

Bytes seal (`read_memory` entry + epilogue):

```text
004e9720  55 8B EC 83 E4 F0 6A FF 68 12 26 9A 00 …   ; frame + SEH
004e97fb  CALL 005eb790                               ; parent query-collect ctor
004e9821  MOV ECX,[EAX+0xE4A4] / CALL 0055ff20         ; host physics register
004e98b5  CALL [EAX+0x30]                               ; collect vcall
004e9a8e  MOV AL,BL … 8B E5 5D C3 CC…                   ; return bool; bare RET; pad
```

---

## 4. Surviving contract for AutoCore

| Contract | Port rule |
|---|---|
| API | `bool FindClearSpawnPosition(host, in_f4, scatter_r, sphere_r, out_f4, cookie, attempts, keep_last)` **cdecl** |
| Success | `true` iff some probe iteration saw **zero** collect hits |
| Failure side-effect | if `keep_last==0`, `out = in`; else last candidate may remain |
| Physics | temporary 0xD0 query-collect + 0x10 sphere; must register/unregister on `host+0xE4A4` |
| Do **not** merge with FindDistanceToTarget / GetObjectsInArea / query ctors |
| Name | keep **`_Inferred`** until product string or PDB |

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on identity/ABI/bool polarity/parent-merge **fail**; only product English, cookie semantics, residual callee duals, and runtime remain open. Never Runtime Confirmed.
