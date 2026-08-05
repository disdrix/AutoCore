# Review B (skeptical / adversarial): `aa_00578270` Object_ResolveTargetViaReaction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-F) |
| **Counterpart** | `reviews/A_aa_00578270_Object_ResolveTargetViaReaction_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + callee decompile. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Surface `void __fastcall FUN(int)` is complete | **Falsified** — **returns pointer**; reaction **this** loaded into ECX |
| 2 | This **is** `CVOGReaction_ResolveObjectTarget` | **Falsified** — thin wrapper; resolve lives at `004bae70` |
| 3 | This directly returns the local player | **Unproven** — returns resolve result; W27-F then `vfunc+0x210(0)` for player |
| 4 | No ECX host (static free function) | **Falsified** — host fields from ECX |
| 5 | Flag is a full dword formal | **Partial** — byte at `+0x660`; push uses EAX after `mov al` (high bytes residual from host — callee likely reads low byte only) |
| 6 | `(id0 & id1) != -1` gate is in **this** body | **Falsified** — gate is inside callee |
| 7 | Few callers | **Falsified** — **19** code callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field map + single call | **High** | Wrong targeting port |
| Non-void return | **High** | Dropped player/mgr resolve |
| Reaction path `+0x688/+0xe4e8` | **High** | Null/wrong subsystem |
| Product types / id English | Medium–Low | Naming / schema only |
| Callee gate policy | Out of scope | Dual `004bae70` later |

---

## 3. Cross-check against raw + bytes + consumers

```
; W27-F Object_ActivatePlayerEnqueueHB pattern:
iVar2 = FUN_00578270();          // must capture EAX
if (iVar2 != 0) {
  piVar3 = FUN_00578270();       // second call (same host ECX)
  player = (*piVar3 + 0x210)(0);
  ...
}
```

Scaffold clean that is `void` and omits reaction-this **must be rejected**. Push of flag via full EAX after `mov al` is a known MSVC-ish residual — do not invent a wide flag type without callee dual.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — object targeting
object? Object_ResolveTargetViaReaction(Host host)
{
    var reaction = host.SubsystemAt0x688.ReactionAt0xE4E8;
    return reaction.ResolveObjectTarget(
        host.FlagAt0x660,
        host.Id0At0x658,
        host.Id1At0x65c);
}
// Not void. Not "get local player" by itself — consumers may vfunc further.
```

---

## 5. Open questions

1. Is `+0x658/+0x65c` a TFID dual-dword or another id scheme?
2. What product type does resolve return (object vs manager)?
3. Why do some sites call this twice back-to-back (null-check then reuse)?
4. Dual seal of `004bae70` / `004e3260` when scheduled.

**Verdict:** **accept-with-gaps**
