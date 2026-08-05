# Review B (skeptical / adversarial): `aa_008c2f50` Client_TryInventoryAutoMergePartialStacks_Notify

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c2f50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-N) |
| **Counterpart** | `reviews/A_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** the merge algorithm | **Falsified** — only calls `FUN_00572ab0`; no stack math in-body |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — decompiler `unaff_EDI`; all host loads are `[edi+…]`; ECX only set for grid thiscall into merge |
| 3 | Always sends `0x204a` | **Falsified** — packet only on dirty AL≠0 after all gates |
| 4 | Busy flag is invented | **Falsified** — same `DAT_00d1a8f6` used by grab/drop peers as pending-op gate |
| 5 | Multiple callers | **Falsified** — sole xref `FUN_008c3ca0` @ `0x008c3da5` |
| 6 | Caller uses return value | **Falsified** — after CALL falls into default `FUN_0087b500`; AL discarded |
| 7 | Packet size inferred only | **Falsified** — explicit `push 8` + `mov eax,8` before send |
| 8 | Grid at host+0x580 directly | **Falsified** — `host=*(EDI+0x580)`, `grid=*(host+0x56c)` |
| 9 | Product class plate present | **Overstated** — structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI host + grid indirection | **High** | Wrong object / null crash |
| Busy gate | **High** | Spurious merges / blocked merges |
| Dirty-only notify | **High** | Spam sector / miss notify |
| Packet opcode/size | **High** | Protocol mismatch |
| 0x204a product meaning | **Low** | Server handler mapping |
| `DAT_00d17768` role | **Low** | Wrong stamp semantics |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
; sole caller FUN_008c3ca0 case (param_3-40000)==4, param_2==8:
cmp  esi, 8
jnz  default
call FUN_008c2f50          ; EDI still = this
; fallthrough → default FUN_0087b500 (return ignored)

; body:
sub  esp, 8
cmp  byte ptr [DAT_00d1a8f6], 0
jnz  ret0
mov  eax, [edi+0x580]
test eax, eax / jz ret0
mov  eax, [eax+0x56c]
test eax, eax / jz ret0
mov  ecx, eax
call InventoryGrid_AutoMergePartialStacks  ; 00572ab0
test al, al / jz ret0
; stamp host+0x564 from table; ESI=host; call 00860700
; pack 0x204a / index / FF / 0; SendSectorPacket size 8
mov  al, 1 / pop esi / add esp,8 / ret
ret0:
xor  al, al / add esp,8 / ret
```

Live decompile ≡ raw. Full-body hex seals both epilogues.

---

## 4. Surviving contract for AutoCore

```
// Port as thin client wrapper only:
if (busy || !host || !grid) return false;
if (!InventoryGrid_AutoMergePartialStacks(grid)) return false;
stamp host field; refresh; send sector {0x204a, index, 0xFF, 0}; return true;
// Do NOT reimplement merge here.
// Preserve EDI host convention or explicit host* arg in ports.
// Do not claim product meaning of 0x204a without server map.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/packet/callee split. Residual product/table/opcode semantics → **accept-with-gaps**.
