# Review B (skeptical / adversarial): `aa_00444850` FourCCFnPtrMap_TryInsert_DAT_00d21958

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444850` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-H) |
| **Counterpart** | `reviews/A_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` |
| **Scratch** | `tmp/a_00444850.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler void/no-arg is complete | **Falsified** — callers set EAX FourCC + ECX handler before CALL |
| 2 | ECX is this* of a C++ object method | **Falsified** — ECX is handler value stored into key; map loaded into EAX |
| 3 | Always inserts even on hit | **Open** — depends on unowned `FUN_00458510` (likely insert-if-absent) |
| 4 | Uses same map as `FUN_00444880` | **Falsified** — sibling loads `DAT_00d21964` |
| 5 | Returns iterator/bool to caller | **Falsified** — out-pair stack-only; bare RET void |
| 6 | Palantir-only product method of host | **Weakened** — only Palantir caller today, but body is generic map insert |
| 7 | Scaffold Palantir callee name is full product | **Rejected** as exclusive English — structural FourCC map name preferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX tag + ECX handler | **High** | wrong registration |
| Map `DAT_00d21958` | **High** | wrong table |
| Side-effect-only void | **High** | expect return |
| Insert-on-hit policy | **Medium** | duplicate/update bugs |
| Handler product roles | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00754680 (device start)
MOV ECX, 0x00990540
MOV EAX, 'EFCT'          ; 0x45464354
CALL FUN_00444850
MOV ECX, 0x009906e0
MOV EAX, 'MRPH'          ; 0x4d525048
CALL FUN_00444850
// then FUN_00444880 with 'SKEL' → other map
```

Handlers begin with SEH prolog patterns (code, not data objects).

---

## 4. Surviving contract for AutoCore

```
// Port as register-ABI map ensure:
void FourCCFnPtrMap_TryInsert_DAT_00d21958(uint32_t tag /*eax*/, void* handler /*ecx*/);
// Map object: DAT_00d21958
// Do not assume stack args; do not assume return value.
// Do not merge with DAT_00d21964 sibling without evidence.
// Hit policy: treat as find-or-insert until FUN_00458510 sealed.
```

---

## 5. Verdict

Adversarial pass confirms A: decompiler under-specified; register ABI + map + tags sealed; callee residual → **accept-with-gaps**.
