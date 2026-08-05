# Review B (skeptical / adversarial): `aa_00943b80` Client_FlushWorldObjectState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00943b80_Client_FlushWorldObjectState_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory`. No `disassemble_bytes`. Own VA `0x00943b80` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` ECX this | Entry uses **EDI** (`[edi+0xe04]`); sites `mov edi,esi` before call | **Falsified** — **EDI this** |
| 2 | No stack args / plain `ret` | Epilogue `C2 04 00` | **Falsified** — **RET 4** |
| 3 | Always full UI teardown | Most sites push **0**; flag gates vtbl `+0x2a8`/`+0x2a4` | **Falsified** as always-full |
| 4 | Is `Client_ClearObjectReferences` | That is `00944d50` (different VA/body) | **Falsified** |
| 5 | Is full `TeardownGameplaySession` | Teardown is `00944b20` and **calls** this with 0 | **Falsified** — subordinate flush |
| 6 | Never takes flag=1 | `FUN_009466f0` site `6a 01` before call | **Falsified** |
| 7 | Only frees one node | Walk loop + Release before re-ring; free path may be incomplete in decompile | **Partial** — multi-node release **High**; free-loop after isnil==0 **Open** |
| 8 | Three-rep diverges | live ≡ raw | **Falsified** |
| 9 | Product name sealed High | No plate strings | **Survives** — keep `_Inferred` / Probable |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI this, stack flag, RET 4 | **High** | Wrong call convention → crash |
| flag=0 soft vs flag=1 extras | **High** | Wrong UI/list side effects |
| Drain `+0xd28` + Release(1) | **High** | Leaks / double-free if inverted |
| Two-pass TFID export | **High** | Missed nearby-object rebuild |
| Nested helper names | **Low** | Documentation only |
| Free-loop when isnil==0 | **Open** | Incomplete free |
| Runtime | **Open** | Shipping leave/reconnect |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  unaff_EDI client; param_1 flag
  clear e04→e894+0x8c; optional 004962b0
  0093e120(0); 00997120; flag UI; 00415e90×2; flag insert
  009306d0; 008026a0; e08=0; soft f38+c70
  drain d28; empty re-ring OR free path
  2× bae00+933370; bbeb0; 92f3b0; flag vtbl 0x2a4

bytes:
  entry 8b87040e0000 …          ; [edi+0xe04]
  exit  83c408 c20400           ; add esp,8; ret 4
sites: 6a00 8bfe e8… / 6a01 … e8…
```

**No conflict** on owned stage CF. Nested bodies not re-proven.

---

## 4. Surviving contract for AutoCore

```csharp
// Client_FlushWorldObjectState @ 0x00943b80
// retail: EDI=client, stack char flag, RET 4

void FlushWorldObjectState(Client client, bool hard)
{
    // always: clear host interact flag; optional equip-gfx list clear;
    //         subsystem helpers; wipe two sub-containers; zero e08;
    //         release objects in d28; re-ring empty; 2× export TFIDs; finish helpers
    // if (!hard && client.F38 != null) client.F38.C70 = 0;
    // if (hard) { UI vtbl 0x2a8; insert into F00; UI vtbl 0x2a4 on exit; }
}
```

Do **not** treat as full session teardown — parent `00944b20` owns that orchestration.

---

## 5. Gaps that survive attack

1. **Product name** — Probable only.
2. **`+0xd28` exact STL type** — structural only.
3. **`operator_delete` free-loop** — decompiler gap.
4. **Nested FUN_*** product names — out of ownership.
5. **Runtime** — not run.

**Verdict:** **accept-with-gaps** — ABI/stages High; naming + free-loop residual.
