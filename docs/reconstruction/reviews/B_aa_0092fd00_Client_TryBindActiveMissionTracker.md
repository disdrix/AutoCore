# Review B (skeptical / adversarial): `aa_0092fd00` Client_TryBindActiveMissionTracker

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092fd00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0092fd00_Client_TryBindActiveMissionTracker.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__cdecl` / no register args | Callers put id in EAX, client in EDI; body uses both | **Falsified** as cdecl |
| 2 | `FUN_0059dc50(character)` thiscall on char | Image: `push esi; mov ecx,eax(node); call` | **Falsified** — this = node |
| 3 | Always refreshes mission UI | Only if binder returns non-zero **and** `+0x107c` live | **Sealed** |
| 4 | FailMission always needs this for correctness | Only on objective-hash **miss** with EAX=0; optional secondary | **Sealed** as optional helper |
| 5 | missionId==0 always calls binder | Early return 1 when tracker `+0x10==0` | **Sealed** — skip binder |
| 6 | Name is product "FailMission helper" only | 9 callers incl. dialog accept + convoy | **Falsified** as fail-only |
| 7 | Return type void | AL success paths; FailMission ignores return | **Sealed** as bool (caller-optional) |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI client / EAX id / AL bool | **High** | Wrong port ABI |
| Hash + gate + binder order | **High** | Miss bind rules |
| Idle short-circuit on zero id | **High** | Spurious UI work |
| `FUN_0059dc50` this = node | **High** | Wrong gate object |
| Product tracker English | **Open** | Doc only |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// custom: EDI=client, EAX=missionId
bool Client_TryBindActiveMissionTracker(Client* client /*EDI*/, uint32_t missionId /*EAX*/);
```

- Non-zero id: require active-objectives hash hit + node gate, then tracker bind.
- Zero id: if tracker already idle return true; else clear via binder.
- UI refresh is best-effort after successful binder.

---

## 4. Verdict

**accept-with-gaps** — adversarial seals dual-register ABI, node-this gate, idle short-circuit, and multi-caller role (not fail-only).
