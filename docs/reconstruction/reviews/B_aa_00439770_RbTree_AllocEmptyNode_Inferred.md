# Review B (skeptical / adversarial): `aa_00439770` RbTree_AllocEmptyNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439770` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00439770_RbTree_AllocEmptyNode_Inferred.md` |
| **Verdict** | **accept** on CF; reject overclaims about full map ctor / void return / self-linked empty tree |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns `void` / no useful result | **Falsified** — EAX = alloc; `FUN_004e7450` assigns result; analyze_function warns undefined return |
| 2 | This unit builds a complete empty `std::map` | **Falsified** — no self-links, no size field, no header object; only node seed |
| 3 | `+0x14`/`+0x15` are RGB color enum with product names | **Overstated** — bytes sealed; English names **Tentative** |
| 4 | Null `operator_new` is safe | **Risk acknowledged** — if `eax==0`, `lea ecx,[eax+4]` yields 4 and may store; first store is guarded, later stores follow decompiler structure. Production uses non-throwing path assumptions; do not port as crash-proof OOM handling without policy |
| 5 | Historical alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` is product name | **Rejected** — weak scaffolding plate only |
| 6 | `puVar1+1 != NULL` is a real heap check | **Artifact** — pointer arithmetic on non-null base is always non-null; do not invent branch semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size / flag offsets | **High** | Wrong node layout → tree corruption |
| EAX return | **High** | Leaked or dropped roots |
| Sentinel role via callers | **High** | Mis-port as general `new Node` with value ctor |
| Product naming | **Low–Tentative** | Docs only |
| OOM path | **Medium** | Rare crash on null new |

---

## 3. Cross-check against caller `FUN_004e7450`

```
iVar1 = FUN_00439770();
*(header+4) = iVar1;
*(iVar1+0x15) = 1;
*(iVar1+4) = iVar1;   // parent = self
*iVar1 = iVar1;       // left = self
*(iVar1+8) = iVar1;   // right = self
*(header+8) = 0;      // size
return header;
```

Therefore **empty-tree construction is split**: this VA allocates/seeds; init wrappers finish the header. Porting only `00439770` as "create empty map" is **wrong**.

---

## 4. Surviving contract for AutoCore

```
node = RbTree_AllocEmptyNode_Inferred():
  p = new(0x18)
  zero p[0], p[1], p[2]
  p.byte[0x14] = 1
  p.byte[0x15] = 0
  return p

// NOT done here:
//   self-links, size=0, header object, value construction
```

---

## 5. Open questions (narrow)

1. Node value_type for size `0x18` beyond sentinel use.
2. Whether any caller uses the node without setting `+0x15=1`.
3. Live CE null-new path.

**Verdict:** **accept** on sealed CF + return + factory role; residual naming/OOM only.
