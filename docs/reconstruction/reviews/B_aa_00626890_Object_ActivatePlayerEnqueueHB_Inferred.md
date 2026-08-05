# Review B (skeptical / adversarial): `aa_00626890` Object_ActivatePlayerEnqueueHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-F) |
| **Counterpart** | `reviews/A_aa_00626890_Object_ActivatePlayerEnqueueHB_Inferred.md` |
| **Scratch** | `tmp/a_00626890.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True `__fastcall` (arg in EDX) | **Falsified** — entry `mov ebp,ecx` seals **thiscall** host; no EDX formal |
| 2 | Has direct CALL callers | **Falsified** — only DATA vtable `@0x009d1ba8` |
| 3 | Optional `FUN_00578b30` | **Falsified** — always executed after player branch |
| 4 | Does not touch TFID | **Falsified** — sole caller of `FUN_004c4880` @ `0x0062690d` |
| 5 | Leaves phys mode alone | **Falsified** — TFID path sets phys `+0x28` mode 10/0xB + rebind (W26-F) |
| 6 | Stack-allocates HB action | **Falsified** — `operator_new(0x2c)` heap |
| 7 | Product name is retail string | **Overstated** — no plate; structural `_Inferred` |
| 8 | `Object_SetSelectedTarget` arity fully known | **Residual** — live shows 3 args with `unaff_ESI` |
| 9 | Null-safe when `operator_new` fails | **Residual** — surface derefs `pAction->pOwnerObject` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + SEH + plain RET | **High** | ABI / EH break |
| Vtable dispatch only | **High** | Wrong hook model |
| TFID rebind linkage | **High** | Stale identity / phys mode |
| HB enqueue + Start order | **High** | Action never ticks / double-start |
| Always fire-tail | **High** | Missing period stamp |
| Product class English | **Medium** | Naming only |
| Nested helper English | **Medium** | Mis-port of ctor args |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_ActivatePlayerEnqueueHB_Inferred(host)  // SEH
related = host+0x18 ? vfunc+0x214() : 0
if related: Object_SetPhysBodyTypeIfNotReady(...)
player = FUN_00578270(); vfunc+0x210(0)
if player:
  Object_SetTFID_ApplyPhysMode_Rebind(player, src=+0x164)
  FUN_0051f890(1)
  // host float gates + phys-sub vcalls
  Object_SetSelectedTarget(player_obj, related_obj, ?)
  pAction = new(0x2c) + FUN_006264e0(host+0x24, player_obj, host)
  if pAction->pOwnerObject: host+0x6c4 = pAction; Enqueue; Start
  player+0x6bb = 0
FUN_00578b30()
RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; surface renames `FUN_005172d0`→`Object_SetSelectedTarget`. Vtable dword `@0x009d1ba8` = `0x00626890`.

---

## 4. Surviving contract for AutoCore

```
// Host vtable activate (do not invent a free-function entry):
Object_ActivatePlayerEnqueueHB_Inferred(host);
// Must: TFID rebind before HB Start; always FUN_00578b30 after
// Must: preserve operator_new(0x2c) + FUN_006264e0(host+0x24, player, host)
// Must: store action at host+0x6c4 only when pOwnerObject non-null
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/TFID sole-caller/HB chain; leaves product class, `unaff_ESI`, and nested ctor English as **gaps** → **accept-with-gaps**.
