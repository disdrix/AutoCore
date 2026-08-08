# Review B (skeptical / adversarial): `aa_0091a350` Client_InteractWorldClick_SoftCastAlt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-033) |
| **Counterpart** | `reviews/A_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True freestanding `void` / no object | **Falsified** — body uses `[ESI]` vtbl and `[ESI+disp]`; call site `MOV ESI,EDI` with EDI=client this |
| 2 | Standard **ECX-thiscall on entry** | **Falsified** — no `MOV ESI,ECX` prologue; ESI already live; virtuals re-load `MOV ECX,ESI` |
| 3 | Stack args / `RET 4` or `RET 8` | **Falsified** — bare `RET` (`C3`); parent cleans its own 8-byte args after return |
| 4 | Primary UseObject / `Client_InteractClickPickTarget` path | **Falsified** — sole caller is hub `00925820`; no `Client_SendUseObject` |
| 5 | Owns select clear (`[+0x758]=0` / `FUN_0093e120(0)`) | **Falsified** — no such store/call; ItemPickup sibling arm does that |
| 6 | Always runs soft-cast FX | **Falsified** — gated on `DAT_00d1b6d8`, `+0x250`, `+0x106`, `+0x284` |
| 7 | Multiple callers / shared utility | **Falsified** — **1** xref only (`00925958`) |
| 8 | Drop-destroy modal owner | **Falsified** — modal string path is sibling when `d1a860!=0` && `char+0xCD0` |
| 9 | Product name without `_Inferred` | **Fails gate** — no PDB/string for method English |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | `FUN_00930fc0` is cast manager / TFID clear | **Falsified** — dualed as `Ui_ResolveEntityNameColor_Inferred` (ARGB label color) |
| 12 | Decompiler `return undefined4` width is ABI | **Weakened** — assembly returns **AL** only; high EAX undefined |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI client + bare RET + AL bool | **Confirmed** | Stack imbalance / wrong this |
| Sole hub caller @ `00925958` | **Confirmed** | Over-generalize system tag |
| `d1a860==0` alternate role | **Confirmed** | Mis-merge with drop/ray arms |
| Soft-cast +0x106/+0x107 clear | **Confirmed** | Miss cancel side-effect |
| Type-2 FX spawn presence | **High** | Wrong VFX taxonomy if `007a0120` misread |
| Name-color call useful vs dead local | **Medium** | Preserve call; do not invent sink |
| Product English name | **Inferred** | Doc only until string/PDB |
| Runtime | **Open** | No Confirmed claim |

---

## 3. Cross-check against raw / bytes

```text
raw scaffold 2026-07-23  ≡  live decompile 2026-08-05  ≡  clean named/twin

Prologue: 55 8B EC 83 E4 F0 83 EC 1C 8B 06 53 8B CE FF 90 D8 03 00 00
          PUSH EBP; MOV EBP,ESP; AND ESP,F0; SUB ESP,1C;
          MOV EAX,[ESI]; PUSH EBX; MOV ECX,ESI; CALL [EAX+0x3D8]

Success:  B0 01 5B 8B E5 5D C3     ; MOV AL,1; POP EBX; leave; RET
Fail:     32 C0 5B 8B E5 5D C3     ; XOR AL,AL; POP EBX; leave; RET

DAT_00aaa668: 00 00 80 BF = -1.0f → [ESI+0x558]
Body: 0x0091a350–0x0091a54a (507 B); pad CC after
Caller: Client_InteractWorldClickHub @ 00925958 only (after CMP [d1a860],AL / JNZ skip)
```

Reject ports that:

- Treat this as ECX-thiscall without fixing ESI-live ABI (or equivalent explicit client param).
- Claim it clears select slot `+0x758` / drives ItemPickup.
- Always emit FX without `+0x106` gate.
- Merge with `Client_InteractClickPickTarget` (primary 25f UseObject hub).
- Claim runtime Confirmed without Launcher evidence.
- Drop name-color call if bit-exact order matters (even if local ARGB looks unused).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail non-drop alternate from InteractWorldClickHub when DAT_00d1a860==0.
// Port: bool SoftCastAlt(Client client) with ESI-this or explicit client.

bool Client_InteractWorldClick_SoftCastAlt(Client client)
{
    if (!client.Vtbl_3D8_Gate())
        return false;

    client.Field558 = -1.0f;
    client.FlagA32 = false;
    client.Vtbl_478_PostClear();

    if (client.SelectEntity != null)
        Ui.ResolveEntityNameColor(client.SelectEntity, uiCtx: GlobalD1A840, out _);

    var ent = GlobalCharacter?.Nested250;
    if (ent != null && ent.SoftCastFlag106)
    {
        ent.SoftCastFlag107 = false;
        var body = ent.Body284;
        if (body != null)
            FxHost.SpawnType2(/* sealed pack: 0.4f, 1.0f, 3.0f, id 0x61, body xyz… */);
    }
    return true;
}
```

---

## 5. Verdict

Path B falsifies free-void / ECX-entry-thiscall / select-clear-owner / multi-caller / UseObject-hub / always-FX / runtime-Confirmed claims.

Surviving sealed contract matches Path A: **accept-with-gaps** (product English + FX dual + runtime open; CF/ABI/caller sealed).
