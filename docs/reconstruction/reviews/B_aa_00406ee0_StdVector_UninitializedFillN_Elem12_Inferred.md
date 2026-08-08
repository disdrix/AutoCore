# Review B (skeptical / adversarial): `aa_00406ee0` StdVector_UninitializedFillN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406ee0` |
| **VA** | `0x00406ee0` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem12_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` Ufill POD **elem 0xC**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is InsertOne / rebind | No index math; no vector host; returns advanced dest only | **Falsified** InsertOne claim |
| 2 | This is uninitialized_copy (range→range) | Parent passes single template value; construct-N loops value→dest | **Falsified** copy-range model |
| 3 | Decompiler `void` / no args is full ABI | Bytes: stack value*, EDI/ESI register formals, **`ret 4`** | **Falsified** void model |
| 4 | Stride 0x28 (neighborhood sibling 00406e50) | Return `*0xC`; callee advances `+0xC` | **Falsified** stride-0x28 |
| 5 | ECX thiscall dest | Dest is **EDI**; ECX reloaded to value* for construct-N | **Falsified** ECX-dest |
| 6 | Grows / reallocates vector | No capacity math; pure fill of provided buffer | **Falsified** grow claim |
| 7 | Leaf with zero callees | Calls `FUN_00409db0` | **Falsified** |
| 8 | Product requires skill-domain name | Generic POD fill; used under InsertN | **Agree** structural `_Inferred` |
| 9 | `ret` plain without stack cleanup | **`C2 04 00`** | **Falsified** plain-ret |
| 10 | Count is always 1 | ESI = parent count; InsertN multi-insert uses variable N | **Falsified** always-1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 / one stack formal + EDI/ESI | **Confirmed** | Stack/register imbalance |
| Fill-N then return end | **Confirmed** | Wrong insert hole plant |
| Stride 12 | **Confirmed** | Wrong element width |
| Role under InsertN | **High** | Mis-attribute grow engine |
| Construct-N 3-dword POD | **High** | Wrong element ctor |
| Runtime | **Open** | No live capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-08-04);
bytes @ 0x00406ee0:
  mov eax,[esp+4]             ; value*
  push eax
  push ecx                    ; phantom / saved
  mov ecx,[esp+0xC]           ; ECX = value*
  push esi                    ; count
  push edi                    ; dest
  call FUN_00409db0
  lea edx,[esi+esi*2]
  add esp,0x10
  lea eax,[edi+edx*4]         ; dest + count*12
  ret 4
```

### ABI trap

Do **not** trust decompiler `int FUN_00406ee0(void)` + `unaff_ESI/EDI` as “undefined behavior.” Parent InsertN sets **EDI=dest**, **ESI=count** immediately before call.

### Phantom-push trap

Extra pushes + `add esp,0x10` are the same MSVC Ufill-wrapper pattern seen on toast/floater FillN units — not evidence of four real formals consumed by construct-N. Construct-N uses **ECX=value*** + two stack formals (dest, count).

---

## 4. Residual gaps (agreed with A)

1. Product type English.  
2. Dual seal of `00409db0` / `00409f50`.  
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; thin wrapper sealed.
