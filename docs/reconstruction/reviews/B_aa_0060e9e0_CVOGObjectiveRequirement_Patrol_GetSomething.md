# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_GetSomething` @ `0x0060e9e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e9e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |
| **Verdict** | **accept on load; rename open** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns progress float | **Falsified — dword +0x28** |
| 2 | Name describes behavior | **Falsified — placeholder** |
| 3 | __fastcall vs __thiscall matters for recompile | **Medium — this in ECX either way for MSVC thiscall-like** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offset +0x28 | High | Wrong continent filter |
| Caller expectations | Medium | Mis-wire HUD |

---

## 3. Surviving contract for AutoCore

```
return *(uint32*)(req + 0x28);
```

---

## 4. Open questions

1. Caller list from Ghidra xrefs.
2. Confirm continent vs range-type dual use of +0x28.

**Verdict:** accept on load; rename open.
