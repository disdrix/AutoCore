# Review B (skeptical / adversarial): `aa_0051aed0` Object_PlayPickupSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-J) |
| **Counterpart** | `reviews/A_aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs). No `disassemble_bytes`. Own VA `0x0051aed0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free `__cdecl` | entry `mov ebx,ecx`; tail `ret 8` | **Falsified** — **thiscall + stdcall-ish ret 8** |
| 2 | Returns FX pointer | void fallthrough | **Falsified** — **void** |
| 3 | Always plays audio | gated by table+600 **and** `param_2` | **Falsified** — audio optional |
| 4 | Quest FX only for quests | type==4 **or** `param_3` | **Partial** — type 4 forced; param_3 force flag |
| 5 | `"commidity"` is agent typo | literal in binary path | **Falsified** — **product spelling** |
| 6 | Rarity always loads | requires short `>1` | **Falsified** — common skips overlay |
| 7 | Paint path is vehicle-only | uses paint lookup + Mat* keys on type tag 8 | **Domain High / product open** |
| 8 | Three-rep diverges | live ≡ prior raw ≡ ret-8 tail | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI / string map / attach order | **High** | wrong client FX port |
| param roles (audio / force-quest) | **High** from CF | wrong call-site flags |
| Product C++ name | **Low–Open** | rename churn |
| vtbl / offset English | **Partial** | wrong object model |
| Runtime / bit-exact | **Open** | shipping parity |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  type switch → NDSpecialFX_LoadFromScriptName(...,4,0)
  rarity overlay if short>1
  FUN_004b8dc0(1,0) + vtbl+0xF8 attach
  optional FUN_004b7e50
  optional paint Mat* path

bytes:
  83 EC 10 … 8B D9 …
  … 5F 5E 5D 5B 83 C4 10 C2 08 00
  DAT_00aaa7a8 = 3B808081h ≈ 1/255
```

**No conflict** on owned ABI/CF/strings.

---

## 4. Surviving contract for AutoCore

```csharp
// Object_PlayPickupSpecialFX @ 0x0051aed0
// retail: ECX=object, stack (bPlayAudio, bForceQuestFx), ret 8, void

void PlayPickupSpecialFX(GameObject self, bool playAudio, bool forceQuestFx)
{
  // Map clone type/rarity → generic_pickup_* scripts;
  // attach FX; optional audio; optional paint material tint.
}
```

Port rules:

- Preserve **script name table** including product typo `generic_pickup_commidity`.
- Do not invent server-side pickup validation here — this is **client FX only**.
- Call-site flags matter: selection init uses `(1,0)`; float-up path passes distance gate + helper flag.
