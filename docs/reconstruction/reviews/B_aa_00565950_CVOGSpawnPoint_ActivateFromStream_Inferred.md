# Review B (skeptical / adversarial): `aa_00565950` CVOGSpawnPoint_ActivateFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00565950` |
| **VA** | `0x00565950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W30-H) |
| **Counterpart** | `reviews/A_aa_00565950_CVOGSpawnPoint_ActivateFromStream_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; atlas + 4th formal residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` / 3-arg thiscall | Epilogue **`C2 10 00`**; early `xor al,al` / success `mov al,1` | **returns 0/1; ret 16** |
| 2 | `param_3` is a pointer (`undefined1*`) | Used as **signed int** version in compares (`0x1d`, `0x1e`, …) | **version int** |
| 3 | Direct CODE callers of body | Xref only from **MI thunk** `00567CBE` | **vtable via adjustor** |
| 4 | String-only name is complete | Neighbors are `CVOGSpawnPoint_*`; layout MI | **family name stronger** |
| 5 | `FUN_00567860` is insert-or-find | W29-M sealed **InsertAlways** | **always-insert** |
| 6 | Bad range uses magic inline float | `read_memory` `DAT_009d2eb8` = **75.0f** | **global constant** |
| 7 | Named clean stub is full body | Twin `FUN_00565950.cpp` holds CF lines | **twin is authoritative body** |
| 8 | Product English in binary for class | Only spawn-point activation strings | **`_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x10 + bool return | **Confirmed** | ABI crash |
| Stream null gate | **Confirmed** | null deref |
| Version-gated layout | **Confirmed** (CF) | wrong field sync |
| 75.0f default | **Confirmed** | wrong gameplay range |
| Full field atlas | Tentative | port incomplete detail |
| 4th stack formal | Open | stack imbalance if inventing args |
| Runtime golden | Open | |

---

## 3. Surviving contract

```
uint32_t CVOGSpawnPoint_ActivateFromStream_Inferred( // thiscall, ret 0x10
    void *spawn_subobject, void *stream, int version, float *world_offset4)
{
  if (!stream) return 0;
  // stream vtbl+0x14 reads; pos += world_offset4;
  // if range<=0: log + range=75.0f;
  // version-gated tables; optional linked spawn; InsertAlways maps;
  return 1;
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Full version field product atlas | No for structural seal |
| R2 | Fourth stack dword identity | No if ports match `ret 0x10` |
| R3 | Nested spawn helper product names | No |
| R4 | Runtime golden | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00565950` — CF matches 2026-07-23 raw.  
2. `read_memory` entry/epilogue — thiscall, **`ret 0x10`**, return 0/1.  
3. `read_memory` `0x009d2eb8` — **75.0f**.  
4. Thunk at `0x00567CBE` computes jmp → `0x00565950`.  
5. Cross-check W29-M InsertAlways call sites inside this body.

---

## 6. Falsifications locked in

- **Reject** treating function as void / plain `ret`.  
- **Reject** `param_3` as byte pointer for I/O size.  
- **Reject** inventing flat memcpy in place of versioned stream reads.  
- **Reject** merge with CreateCreature / SetObjectActiveState (different VAs).

---

## 7. Verdict

**accept-with-gaps** — structural seal holds; atlas/4th-arg/runtime remain open without blocking dual.
