# Review B (skeptical / adversarial): `aa_005d49e0` Object_CompositeStopTypeF_MIEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d49e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-K dual B) |
| **Counterpart** | `reviews/A_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_005d49e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Body is bare `call A; call B; ret` with no this-adjust | **Falsified** — LEA `−0x90` and `−0x10` before each call |
| 2 | cdecl / plain ret | **Falsified** — `C2 04 00` |
| 3 | Decompiler signature is complete ABI | **Overstated** — missing thiscall + stack param + adjusts |
| 4 | Multiple direct CALL factories into this unit | **Falsified** — 4 xrefs are JMP MI adjustors only |
| 5 | This unit implements type-0xF walk itself | **Falsified** — work in `00581500` → `00514d80` |
| 6 | First callee ignores this adjust | **Falsified** — `0053d4b0` uses ECX; probes `*(this-0x48)` after adjust |
| 7 | Product name confirmed | **Overstated** — structural `_Inferred` only |
| 8 | Same this for both callees | **Falsified** — distinct LEA bases |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / adjusts / ret 4 / callees | **High** | Wrong this / ABI break |
| JMP-only entry model | **High** | Wrong caller model |
| Product spelling | **Medium** | Naming only |
| Nested 0053d4b0 field meaning | **Open** | Port comment depth |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw decompile: FUN_0053d4b0(param); FUN_00581500(param); return;
bytes: push esi/edi; edi=param; esi=this;
       push edi; lea ecx,[esi-0x90]; call 0053d4b0;
       push edi; lea ecx,[esi-0x10]; call 00581500;
       pop; pop; ret 4
```

Clean **must**:
- apply both this-adjusts,
- preserve `ret 4` and one stack formal,
- not inline type-0xF or 005070d0 bodies,
- not invent null checks.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_005d49e0 — Object_CompositeStopTypeF_MIEntry_Inferred
// thiscall; ret 4; void
unsafe void MIEntry(void* self, uint param)
{
    FUN_0053d4b0((byte*)self - 0x90, param);
    Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred((byte*)self - 0x10);
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI/callee adjusts; product English remains `_Inferred` only → **accept**.
