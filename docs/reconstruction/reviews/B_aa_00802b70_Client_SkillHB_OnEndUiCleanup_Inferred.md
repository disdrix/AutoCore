# Review B (skeptical / adversarial): `aa_00802b70` Client_SkillHB_OnEndUiCleanup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00802b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md` |
| **Agent** | MEGA-020 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI/OnEnd-hook role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is a direct CODE callee of Client InitInstance | **Falsified** — InitInstance only **stores** address into `PTR_FUN_00af31e0`; no `CALL 00802b70`. Xref is DATA. |
| 2 | `Named_CalleeOf_Named_Client_InitInstance_*` is correct role | **Falsified** — registration ≠ invocation; live invoker is skill HB OnEnd |
| 3 | Thiscall ECX = skill HB | **Falsified** — prologue loads stack arg into EDI; `RET 0x8`; ECX only for nested thiscalls |
| 4 | Single stack arg (decompiler signature) | **Falsified** — epilogue `C2 08 00`; OnEnd pushes two (`hb`, `0`) |
| 5 | Arg2 is a mode / flags input used in body | **Falsified** — no load of second arg; always `0` from OnEnd |
| 6 | This is FireTail / OnHeartBeat | **Falsified** — FireTail client hook is sibling `PTR_FUN_00af31e4` → `FUN_00802c80`; OnEnd dual documents `00af31e0` as end hook |
| 7 | Always rebuilds vehicle inv sheet | **Falsified** — only local-owner branch + `vtbl+0x3d8` truthy |
| 8 | Always calls `FUN_008027e0` | **Falsified** — only non-local branch after `+0xfe` + resolve local gates |
| 9 | `FUN_007fc970` is true void with no context | **Falsified** — caller sets `ESI = 0x00d1a840`; callee writes `ESI+0x30a0` sheet |
| 10 | Product name is retail symbol | **Unproven** — `_Inferred` required |
| 11 | Runtime Confirmed without Launcher | **Rejected** — Terminal false |
| 12 | Has direct CODE callers listed by Ghidra | **Falsified** — `get_function_callers` empty; indirect via PTR only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall RET 8 / 2 args | **Confirmed** | Wrong port ABI / stack corruption |
| OnEnd PTR hook role | **Confirmed** | Wrong lifecycle wiring vs FireTail twin |
| Local vs non-local branch split | **Confirmed** | Wrong UI rebuild vs panel teardown |
| `+0xfe` gate on non-local only | **Confirmed** | Spurious teardown |
| Product English | Inferred | Cosmetic rename only |
| Nested residual callee English | Open | Port may keep FUN_* until dualed |

---

## 3. Cross-check

```
InitInstance 94a6a0:
  MOV [00af31e0], 802b70   ← this unit (OnEnd UI cleanup)
  MOV [00af31e4], 802c80   ← FireTail client hook twin

OnEnd 578ce0 (dualed):
  call [00af31e0](hb, 0)  ← first action; then resolve/clear/cast/…

FireTail path (sibling, not this VA):
  uses 00af31e4 → FUN_00802c80 (different CF; includes SummonSnoop RTTI)

FUN_007fc970:
  ESI-relative clear of client+0x30a0 sheet bind (+0x514 / +0x4fc)
  Same clear pattern reappears in FUN_0083bf40 when tracker matches

Object_ResolveTargetViaReaction 578270 (dualed):
  thiscall ECX=hb; used only on non-local path here
```

**Attack on “this ends the skill simulation”:** body only touches UI globals / sheet rebuild / panel list — combat OnEnd work lives in parent `00578ce0` after the PTR call. Do not overclaim simulation teardown.

**Attack on “always removes from UI list”:** `FUN_0083bf40` only when `DAT_00d1b8ec` and `+0x590` non-null; early returns can skip it (null hb; no local; no owner; non-local fail gates).

---

## 4. Surviving contract for AutoCore

```
// Client skill-HB OnEnd UI cleanup (PTR_FUN_00af31e0):
// stdcall(skillHb, unused=0) RET 8
// 1) if UI tracker+0x514 == hb: clear client sheet bind (007fc970 / ESI client)
// 2) if local player + owner:
//      if owner is local-keyed:
//          maybe rebuild vehicle inv stats labels (0087d810)
//      else if hb+0xfe && resolve target is local-keyed:
//          FUN_008027e0(owner)
//      if UI host list: FUN_0083bf40(list, hb)
```

Port notes:
- Install into the same function-pointer slot the parent OnEnd calls; do not hard-link only from InitInstance.
- Keep distinct from FireTail twin `FUN_00802c80` / `PTR_FUN_00af31e4`.
- Preserve three re-resolve calls on the non-local path (exact call count).
- Do not invent product names for residual callees.

---

## 5. Gaps

1. Product English / MSVC demangle.
2. Nested residual duals (`007fc970`, `008027e0`, `0083bf40`).
3. Owner/target vfunc English.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
