# Review B (skeptical / adversarial): `aa_00611690` CVOGObjectiveRequirement_Collect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| **Verdict** | **accept-with-gaps** on type=2 / vtable / ABI / size `0x68`; falsify conflation with Deliver / Eval |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Type code is **4** (event-ish) | Body writes imm **2** at `+0x0c`; event **4** is Deliver OnInventoryEvent param, not ctor type | **Falsified** — type **2** |
| 2 | This is Deliver ctor | Deliver is `0x00610bc0`, type **3**, vtable `0x009e0f24`, smaller init set | **Falsified** |
| 3 | Ctor counts cargo / sets progress | Body is stores only; no `CountItemsByCbid`, no float progress | **Falsified** |
| 4 | Type string `"Collect"` ASCII | Factory compares UTF-16 `"collect"` @ `0x009d0b34` | **Falsified as ASCII** — wide lower |
| 5 | Object size = sizeof(base) only | Factory `PUSH 0x68` before new; fields to `+0x64` | **Falsified** — **0x68** |
| 6 | `__cdecl` / no callee cleanup | Epilogue `C2 04 00` | **Falsified** — thiscall + RET 4 |
| 7 | Multiple production callers | Xrefs: single call `0x00547337` in factory | **Falsified** (one site) |
| 8 | `param_1[0x12]=0` is integer zero of unrelated field | Asm `F3 0F 11 46 48` = **movss** 0.0f → `+0x48` | **Falsified as int** — float drop% |
| 9 | Vtable remains base `009e3bac` | Collect overwrites `*this` with `009e12c4` after base | **Falsified** |
| 10 | CBID defaults to 0 | `OR EAX,-1` then `MOV [ESI+0x10],EAX` | **Falsified** — **−1** sentinel |
| 11 | NumToCollect defaults to −1 | `XOR ECX,ECX` / `MOV [ESI+0x14],ECX` | **Falsified** — **0** |
| 12 | Type=2 means “use item” | UseItem is separate class/vtable family; Collect RTTI + inventory Eval sealed elsewhere | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type dword **2** @ `+0x0c` | **High** | Wrong RequirementType enum / server mirror |
| Vtable `0x009e12c4` | **High** | Wrong virtual Action/Eval/SlotAction |
| RET 4 / parent stack | **High** | ABI crash in reimpl |
| Alloc **0x68** | **High** | Heap overrun if smaller type used |
| CBID −1 / Num 0 / drop% 0.0f | **High** | Bad pre-XML defaults |
| Class = Collect | **High** | Name churn only if RTTI wrong (bytes show Collect) |
| Every sentinel field English name | **Open** | Doc-only |
| `+0x08` unwritten | **Open** | If readers assume zero without allocator policy |
| Runtime | **Open** | Edge: OOM path before ctor |

---

## 3. Cross-check: body vs sibling Deliver

| | Collect `0x00611690` | Deliver `0x00610bc0` |
|--|----------------------|----------------------|
| Type @ `+0x0c` | **2** | **3** |
| Vtable | `0x009e12c4` | `0x009e0f24` |
| Base | same `FUN_00637da0` | same |
| CBID `+0x10` | −1 | −1 |
| Extra | large −1 pad block + float `+0x48` | compact flags @ `+0x20`..`+0x23` |
| Factory wide name | `"collect"` | `"deliver"` @ `0x009d0b24` |
| Factory size | **0x68** | (other push; not this unit) |

---

## 4. Byte anchors (adversarial re-read)

```text
0x00611690: 8B 44 24 04 56 50 8B F1 E8 .. .. .. ..   ; parent, this→ESI, base
            0F 57 C0 83 C8 FF 89 46 10                 ; xmm0=0; eax=-1; [+0x10]=-1
            C7 06 C4 12 9E 00                          ; *this = 0x009e12c4
            C7 46 0C 02 00 00 00                       ; [+0x0c] = 2   ← SEAL type
            33 C9 88 4E 18 89 4E 14                    ; ecx=0; [+0x18]u8; [+0x14]=0
            ... 89 46 xx (−1 cluster) ...
            F3 0F 11 46 48                             ; movss [+0x48], 0.0f
            88 4E 19 88 4E 58 8B C6 5E C2 04 00        ; flags; return this; RET 4
```

Factory:

```text
0x00547306: PUSH 0x68
0x00547308: CALL allocator
0x00547337: CALL 0x00611690
; prior string push 0x009d0b34 = u"collect"
```

---

## 5. What would reverse the seal?

- Live body at `0x00611690` writing a type other than 2 (image patch / wrong binary).  
- RTTI / factory string pointing at a different class while still calling this VA.  
- Second production constructor for Collect that installs a different type code.

None observed on current `autoassault.exe` static image.

---

## 6. Gaps (aligned with A)

1. Unwritten `+0x08`.  
2. Sentinel field English names beyond CBID / Num / OptionalDropPercent.  
3. Base class product symbol.  
4. Full factory switch table (parent unit).  
5. Runtime / bit-exact.
