
int main(int ,char **)
{
  std::cout<<;
  const int N = 1000;
  double *rose_temp__4;
  {
    RAJA::Index_type size__2 = (N * N);
    double *ptr;
    ptr = (new double [size]);
    {
      rose_temp__4 = ptr;
      goto rose_inline_end__3;
    }
rose_inline_end__3:
    ;
  }
  double *A = rose_temp__4;
  double *rose_temp__8;
  {
    RAJA::Index_type size__6 = (N * N);
    double *ptr;
    ptr = (new double [size]);
    {
      rose_temp__8 = ptr;
      goto rose_inline_end__7;
    }
rose_inline_end__7:
    ;
  }
  double *B = rose_temp__8;
  double *rose_temp__12;
  {
    RAJA::Index_type size__10 = (N * N);
    double *ptr;
    ptr = (new double [size]);
    {
      rose_temp__12 = ptr;
      goto rose_inline_end__11;
    }
rose_inline_end__11:
    ;
  }
  double *C = rose_temp__12;
  for (int row = 0; row < N; ++row) {
    for (int col = 0; col < N; ++col) {
      A[col + N * row] = row;
      B[col + N * row] = col;
    }
  }
  std::cout<<;
  memset(C,0,(N * N) * sizeof(double ));
  for (int row = 0; row < N; ++row) {
    for (int col = 0; col < N; ++col) {
      double dot = 0.0;
      for (int k = 0; k < N; ++k) {
        dot += A[k + N * row] * B[col + N * k];
      }
      C[col + N * row] = dot;
    }
  }
  {
    double *C__14 = C;
    int N__15 = N;
    bool match = true;
    for (int row = 0; row < N__15; ++row) {
      for (int col = 0; col < N__15; ++col) {
        if (std::abs(C__14[col + N__15 * row] - (row * col * N__15)) > 10e-12) {
          match = false;
        }
      }
    }
    if (match) {
      std::cout<<;
    }
    else {
      std::cout<<;
    }
rose_inline_end__16:
    ;
  }
  RAJA::RangeSegment row_range(0,N);
  RAJA::RangeSegment col_range(0,N);
  RAJA::RangeSegment dot_range(0,N);
  struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Aview(A,N,N);
  struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Bview(B,N,N);
  struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Cview(C,N,N);
  std::cout<<;
  memset(C,0,(N * N) * sizeof(double ));
  {
    RAJA::RangeSegment &args__18 = row_range;
    class &&args__19 =  [=] (int row)
    {
      for (int col = 0; col <  N; ++col) {
        double dot = 0.0;
        for (int k = 0; k <  N; ++k) {
          dot +=  Aview(row,k) *  Bview(k,col);
        }
        Cview(row,col) = dot;
      }
    };
    struct RAJA::RAJA::util::PluginContext rose_temp__69;
    {
      {
        rose_temp__69 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
        goto rose_inline_end__68;
      }
rose_inline_end__68:
      ;
    }
    struct RAJA::RAJA::util::PluginContext context = rose_temp__69;
    {
      struct RAJA::RAJA::util::PluginContext p__71 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__133 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__136;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__134 = &rose_temp__133;
          {
            rose_temp__136 = (this__134 -> object);
            goto rose_inline_end__135;
          }
rose_inline_end__135:
          ;
        }
        rose_temp__136 ->  preLaunch (p__71);
      }
rose_inline_end__72:
      ;
    }
    {
      struct RAJA::policy::loop::loop_exec &&p__74 = RAJA::policy::loop::loop_exec ();
      RAJA::RangeSegment &c__75 = std::forward< RAJA::RangeSegment & > (args__18);
      class &&loop_body__76 = std::forward<   > (args__18);
      using RAJA::internal::trigger_updates_before;
      std::remove_reference< &> ::type rose_temp__140;
      {
        class &item__138 = loop_body__76;
        {
          rose_temp__140 = (item__138);
          goto rose_inline_end__139;
        }
rose_inline_end__139:
        ;
      }
      auto body = rose_temp__140;
      {
        const struct RAJA::policy::loop::loop_exec &__142 = std::forward< class RAJA::policy::loop::loop_exec  > (p__74);
        RAJA::RangeSegment &iter__143 = std::forward< RAJA::RangeSegment & > (c__75);
        std::remove_reference< &> ::type &body__144 = body;
        using std::begin;
        using std::end;
        using std::distance;
        auto begin_it = std::begin(iter__143);
        auto end_it = std::end(iter__143);
        auto distance_it = std::distance(begin_it,end_it);
        for (std::__iterator_traits< ,std::__void_t<   > > ::difference_type i = 0; i < distance_it; ++i) {
          auto rose_temp__212 = body__144;
          {
            int row__214 = (operator*());
            for (int col = 0; col < N; ++col) {
              double dot = 0.0;
              for (int k = 0; k < N; ++k) {
                dot += row__214operator() * koperator();
              }
              row__214operator() = dot;
            }
rose_inline_end__215:
            ;
          }
        }
rose_inline_end__145:
        ;
      }
rose_inline_end__77:
      ;
    }
    {
      struct RAJA::RAJA::util::PluginContext p__79 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__146 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__149;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__147 = &rose_temp__146;
          {
            rose_temp__149 = (this__147 -> object);
            goto rose_inline_end__148;
          }
rose_inline_end__148:
          ;
        }
        rose_temp__149 ->  postLaunch (p__79);
      }
rose_inline_end__80:
      ;
    }
rose_inline_end__20:
    ;
  }
  {
    struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Cview__22 = (Cview);
    int N__23 = N;
    bool match = true;
    for (int row = 0; row < N__23; ++row) {
      for (int col = 0; col < N__23; ++col) {
        if (std::abs(Cview__22(row,col) - (row * col * N__23)) > 10e-12) {
          match = false;
        }
      }
    }
    if (match) {
      std::cout<<;
    }
    else {
      std::cout<<;
    }
rose_inline_end__24:
    ;
  }
  std::cout<<;
  memset(C,0,(N * N) * sizeof(double ));
  {
    RAJA::RangeSegment &args__26 = row_range;
    class &&args__27 =  [=] (int row)
    {
      {
        const RAJA::RangeSegment &args__30 =  col_range;
        class &&args__31 =  [=] (int col)
        {
          double dot = 0.0;
          for (int k = 0; k <  N; ++k) {
            dot +=  Aview(( row),k) *  Bview(k,col);
          }
          Cview(( row),col) = dot;
        };
        struct RAJA::RAJA::util::PluginContext rose_temp__83;
        {
          {
            rose_temp__83 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
            goto rose_inline_end__82;
          }
rose_inline_end__82:
          ;
        }
        struct RAJA::RAJA::util::PluginContext context = rose_temp__83;
        {
          struct RAJA::RAJA::util::PluginContext p__85 = context;
          for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
            auto rose_temp__150 =  * plugin;
            class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__153;
            {
              const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__151 = &rose_temp__150;
              {
                rose_temp__153 = (this__151 -> object);
                goto rose_inline_end__152;
              }
rose_inline_end__152:
              ;
            }
            rose_temp__153 ->  preLaunch (p__85);
          }
rose_inline_end__86:
          ;
        }
        {
          struct RAJA::policy::loop::loop_exec &&p__88 = RAJA::policy::loop::loop_exec ();
          const RAJA::RangeSegment &c__89 = std::forward< const RAJA::RangeSegment & > (args__30);
          class &&loop_body__90 = std::forward<   > (args__30);
          using RAJA::internal::trigger_updates_before;
          std::remove_reference< &> ::type rose_temp__157;
          {
            class &item__155 = loop_body__90;
            {
              rose_temp__157 = (item__155);
              goto rose_inline_end__156;
            }
rose_inline_end__156:
            ;
          }
          auto body = rose_temp__157;
          {
            const struct RAJA::policy::loop::loop_exec &__159 = std::forward< class RAJA::policy::loop::loop_exec  > (p__88);
            const RAJA::RangeSegment &iter__160 = std::forward< const RAJA::RangeSegment & > (c__89);
            std::remove_reference< &> ::type &body__161 = body;
            using std::begin;
            using std::end;
            using std::distance;
            auto begin_it = std::begin(iter__160);
            auto end_it = std::end(iter__160);
            auto distance_it = std::distance(begin_it,end_it);
            for (std::__iterator_traits< ,std::__void_t<   > > ::difference_type i = 0; i < distance_it; ++i) {
              auto rose_temp__216 = body__161;
              {
                int col__218 = (operator*());
                double dot = 0.0;
                for (int k = 0; k < N; ++k) {
                  dot += rowoperator() * koperator();
                }
                rowoperator() = dot;
rose_inline_end__219:
                ;
              }
            }
rose_inline_end__162:
            ;
          }
rose_inline_end__91:
          ;
        }
        {
          struct RAJA::RAJA::util::PluginContext p__93 = context;
          for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
            auto rose_temp__163 =  * plugin;
            class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__166;
            {
              const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__164 = &rose_temp__163;
              {
                rose_temp__166 = (this__164 -> object);
                goto rose_inline_end__165;
              }
rose_inline_end__165:
              ;
            }
            rose_temp__166 ->  postLaunch (p__93);
          }
rose_inline_end__94:
          ;
        }
rose_inline_end__32:
        ;
      }
    };
    struct RAJA::RAJA::util::PluginContext rose_temp__97;
    {
      {
        rose_temp__97 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
        goto rose_inline_end__96;
      }
rose_inline_end__96:
      ;
    }
    struct RAJA::RAJA::util::PluginContext context = rose_temp__97;
    {
      struct RAJA::RAJA::util::PluginContext p__99 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__167 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__170;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__168 = &rose_temp__167;
          {
            rose_temp__170 = (this__168 -> object);
            goto rose_inline_end__169;
          }
rose_inline_end__169:
          ;
        }
        rose_temp__170 ->  preLaunch (p__99);
      }
rose_inline_end__100:
      ;
    }
    {
      struct RAJA::policy::loop::loop_exec &&p__102 = RAJA::policy::loop::loop_exec ();
      RAJA::RangeSegment &c__103 = std::forward< RAJA::RangeSegment & > (args__26);
      class &&loop_body__104 = std::forward<   > (args__26);
      using RAJA::internal::trigger_updates_before;
      std::remove_reference< &> ::type rose_temp__174;
      {
        class &item__172 = loop_body__104;
        {
          rose_temp__174 = (item__172);
          goto rose_inline_end__173;
        }
rose_inline_end__173:
        ;
      }
      auto body = rose_temp__174;
      {
        const struct RAJA::policy::loop::loop_exec &__176 = std::forward< class RAJA::policy::loop::loop_exec  > (p__102);
        RAJA::RangeSegment &iter__177 = std::forward< RAJA::RangeSegment & > (c__103);
        std::remove_reference< &> ::type &body__178 = body;
        using std::begin;
        using std::end;
        using std::distance;
        auto begin_it = std::begin(iter__177);
        auto end_it = std::end(iter__177);
        auto distance_it = std::distance(begin_it,end_it);
        for (std::__iterator_traits< ,std::__void_t<   > > ::difference_type i = 0; i < distance_it; ++i) {
          auto rose_temp__220 = body__178;
          {
            int row__222 = (operator*());
            {
              const RAJA::RangeSegment &args__30 = col_range;
              class &&args__31 =  [=] (int col)
              {
                double dot = 0.0;
                for (int k = 0; k < N; ++k) {
                  dot += rowoperator() * koperator();
                }
                rowoperator() = dot;
              };
              struct RAJA::RAJA::util::PluginContext rose_temp__83;
              {
                {
                  rose_temp__83 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
                  goto rose_inline_end__82__1;
                }
rose_inline_end__82__1:
                ;
              }
              struct RAJA::RAJA::util::PluginContext context = rose_temp__83;
              {
                struct RAJA::RAJA::util::PluginContext p__85 = context;
                for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); (RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end())operator!=; operator++()) {
                  auto rose_temp__150 = operator*();
                  class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__153;
                  {
                    const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__151 = &rose_temp__150;
                    {
                      rose_temp__153 = (object);
                      goto rose_inline_end__152__2;
                    }
rose_inline_end__152__2:
                    ;
                  }
                  preLaunch(p__85);
                }
rose_inline_end__86__3:
                ;
              }
              {
                struct RAJA::policy::loop::loop_exec &&p__88 = RAJA::policy::loop::loop_exec ();
                const RAJA::RangeSegment &c__89 = std::forward< const RAJA::RangeSegment & > (args__30);
                class &&loop_body__90 = std::forward<   > (args__30);
                using RAJA::internal::trigger_updates_before;
                std::remove_reference< &> ::type rose_temp__157;
                {
                  class &item__155 = loop_body__90;
                  {
                    rose_temp__157 = (item__155);
                    goto rose_inline_end__156__4;
                  }
rose_inline_end__156__4:
                  ;
                }
                auto body = rose_temp__157;
                {
                  const struct RAJA::policy::loop::loop_exec &__159 = std::forward< class RAJA::policy::loop::loop_exec  > (p__88);
                  const RAJA::RangeSegment &iter__160 = std::forward< const RAJA::RangeSegment & > (c__89);
                  std::remove_reference< &> ::type &body__161 = body;
                  using std::begin;
                  using std::end;
                  using std::distance;
                  auto begin_it = std::begin(iter__160);
                  auto end_it = std::end(iter__160);
                  auto distance_it = std::distance(begin_it,end_it);
                  for (std::__iterator_traits< ,std::__void_t<   > > ::difference_type i = 0; i < distance_it; ++i) {
                    auto rose_temp__216 = body__161;
                    {
                      int col__218 = (operator*());
                      double dot = 0.0;
                      for (int k = 0; k < N; ++k) {
                        dot += row__222operator() * koperator();
                      }
                      row__222operator() = dot;
rose_inline_end__219__5:
                      ;
                    }
                  }
rose_inline_end__162__6:
                  ;
                }
rose_inline_end__91__7:
                ;
              }
              {
                struct RAJA::RAJA::util::PluginContext p__93 = context;
                for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); (RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end())operator!=; operator++()) {
                  auto rose_temp__163 = operator*();
                  class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__166;
                  {
                    const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__164 = &rose_temp__163;
                    {
                      rose_temp__166 = (object);
                      goto rose_inline_end__165__8;
                    }
rose_inline_end__165__8:
                    ;
                  }
                  postLaunch(p__93);
                }
rose_inline_end__94__9:
                ;
              }
rose_inline_end__32__10:
              ;
            }
rose_inline_end__223:
            ;
          }
        }
rose_inline_end__179:
        ;
      }
rose_inline_end__105:
      ;
    }
    {
      struct RAJA::RAJA::util::PluginContext p__107 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__180 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__183;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__181 = &rose_temp__180;
          {
            rose_temp__183 = (this__181 -> object);
            goto rose_inline_end__182;
          }
rose_inline_end__182:
          ;
        }
        rose_temp__183 ->  postLaunch (p__107);
      }
rose_inline_end__108:
      ;
    }
rose_inline_end__28:
    ;
  }
  {
    struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Cview__34 = (Cview);
    int N__35 = N;
    bool match = true;
    for (int row = 0; row < N__35; ++row) {
      for (int col = 0; col < N__35; ++col) {
        if (std::abs(Cview__34(row,col) - (row * col * N__35)) > 10e-12) {
          match = false;
        }
      }
    }
    if (match) {
      std::cout<<;
    }
    else {
      std::cout<<;
    }
rose_inline_end__36:
    ;
  }
  std::cout<<;
  memset(C,0,(N * N) * sizeof(double ));
  //---------------beginning -----------------------------
  using EXEC_POL = RAJA::RAJA::KernelPolicy<   > ;
  {
    struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > rose_temp__45;
    {
      RAJA::RangeSegment &args__42 = col_range;
      RAJA::RangeSegment &args__43 = row_range;
      {
        rose_temp__45 = camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  > ,class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  > > (std::forward< RAJA::RangeSegment & > (args__42),std::forward< RAJA::RangeSegment & > (args__42));
        goto rose_inline_end__44;
      }
rose_inline_end__44:
      ;
    }
    struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&segments__38 = rose_temp__45;
    class &&bodies__39 =  [=] (int col,int row)
    {
      double dot = 0.0;
      for (int k = 0; k <  N; ++k) {
        dot +=  Aview(row,k) *  Bview(k,col);
      }
      Cview(row,col) = dot;
    };
    {
      struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&segments__110 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (segments__38);
      class camp::tuple<   > rose_temp__116;
      {
        {
          rose_temp__116 = {};
          goto rose_inline_end__115;
        }
rose_inline_end__115:
        ;
      }
      class camp::tuple<   > &&params__111 = rose_temp__116;
      class &&bodies__112 = std::forward<   > (bodies__39);
      struct RAJA::RAJA::util::PluginContext rose_temp__186;
      {
        {
          rose_temp__186 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
          goto rose_inline_end__185;
        }
rose_inline_end__185:
        ;
      }
      struct RAJA::RAJA::util::PluginContext context = rose_temp__186;
      {
        struct RAJA::RAJA::util::PluginContext p__188 = context;
        for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
          auto rose_temp__224 =  * plugin;
          class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__227;
          {
            const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__225 = &rose_temp__224;
            {
              rose_temp__227 = (this__225 -> object);
              goto rose_inline_end__226;
            }
rose_inline_end__226:
            ;
          }
          rose_temp__227 ->  preLaunch (p__188);
        }
rose_inline_end__189:
        ;
      }
      using segment_tuple_t = RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type ;
      using param_tuple_t = camp::decay< class camp::tuple<   >  > ;
      using loop_data_t = struct RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple<   >  >  , camp::decay<  >  > ;
      decltype(make_wrapped_tuple_impl((forward< class camp::tuple< TypedRangeSegment< Index_type  , make_signed_t< strip_index_type_t< Index_type  >  >  >  , TypedRangeSegment< Index_type  , make_signed_t< strip_index_type_t< Index_type  >  >  >  >  > ()),camp::int_seq< camp::idx_t  , 0L , 1L > {})) rose_temp__193;
      {
        struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&t__191 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (segments__110);
        {
          {
            struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&t__229 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__191);
            camp::idx_seq<   > __230 = {};
            {
              {
                camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__300;
                {
                  struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__298 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__229);
                  using camp::internal::tpl_get_store;
                  static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 0L,"index out of range");
                  {
                    auto rose_temp__343 = static_cast < struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__298 . base);
                    {
                      struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__344 = &rose_temp__343;
                      {
                        rose_temp__300 = this__344 -> val;
                        goto rose_inline_end__345;
                      }
rose_inline_end__345:
                      ;
                    }
                    goto rose_inline_end__299;
                  }
rose_inline_end__299:
                  ;
                }
                auto rose_temp__293 = rose_temp__300;
                RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__296;
                {
                  camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__294 = &rose_temp__293;
                  {
                    rose_temp__296 = (this__294 -> m_begin);
                    goto rose_inline_end__295;
                  }
rose_inline_end__295:
                  ;
                }
                camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__308;
                {
                  struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__306 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__229);
                  using camp::internal::tpl_get_store;
                  static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 0L,"index out of range");
                  {
                    auto rose_temp__346 = static_cast < struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__306 . base);
                    {
                      struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__347 = &rose_temp__346;
                      {
                        rose_temp__308 = this__347 -> val;
                        goto rose_inline_end__348;
                      }
rose_inline_end__348:
                      ;
                    }
                    goto rose_inline_end__307;
                  }
rose_inline_end__307:
                  ;
                }
                auto rose_temp__301 = rose_temp__308;
                RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__304;
                {
                  camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__302 = &rose_temp__301;
                  {
                    rose_temp__304 = (this__302 -> m_end);
                    goto rose_inline_end__303;
                  }
rose_inline_end__303:
                  ;
                }
                struct RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > &&args__290 = RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator ,RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType > {rose_temp__296,rose_temp__304};
                camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__316;
                {
                  struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__314 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__229);
                  using camp::internal::tpl_get_store;
                  static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 1L,"index out of range");
                  {
                    auto rose_temp__349 = static_cast < struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__314 . base);
                    {
                      struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__350 = &rose_temp__349;
                      {
                        rose_temp__316 = this__350 -> val;
                        goto rose_inline_end__351;
                      }
rose_inline_end__351:
                      ;
                    }
                    goto rose_inline_end__315;
                  }
rose_inline_end__315:
                  ;
                }
                auto rose_temp__309 = rose_temp__316;
                RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__312;
                {
                  camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__310 = &rose_temp__309;
                  {
                    rose_temp__312 = (this__310 -> m_begin);
                    goto rose_inline_end__311;
                  }
rose_inline_end__311:
                  ;
                }
                camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__324;
                {
                  struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__322 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__229);
                  using camp::internal::tpl_get_store;
                  static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 1L,"index out of range");
                  {
                    auto rose_temp__352 = static_cast < struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__322 . base);
                    {
                      struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__353 = &rose_temp__352;
                      {
                        rose_temp__324 = this__353 -> val;
                        goto rose_inline_end__354;
                      }
rose_inline_end__354:
                      ;
                    }
                    goto rose_inline_end__323;
                  }
rose_inline_end__323:
                  ;
                }
                auto rose_temp__317 = rose_temp__324;
                RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__320;
                {
                  camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__318 = &rose_temp__317;
                  {
                    rose_temp__320 = (this__318 -> m_end);
                    goto rose_inline_end__319;
                  }
rose_inline_end__319:
                  ;
                }
                struct RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > &&args__291 = RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator ,RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType > {rose_temp__312,rose_temp__320};
                {
                  rose_temp__193 = camp::tuple< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > ,class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > > (std::forward< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  >  > (args__290),std::forward< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  >  > (args__290));
                  goto rose_inline_end__292;
                }
rose_inline_end__292:
                ;
              }
              goto rose_inline_end__231;
            }
rose_inline_end__231:
            ;
          }
          goto rose_inline_end__192;
        }
rose_inline_end__192:
        ;
      }
      loop_data_t loop_data(rose_temp__193,std::forward< class camp::tuple<   >  > (params__111),std::forward<   > (bodies__112));
      using loop_types_t = RAJA::RAJA::internal::makeInitialLoopTypes< class RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple<   >  >  , camp::decay<  >  >  > ;
      {
        struct RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple<   >  >  , camp::decay<  >  > &data__195 = loop_data;
        RAJA::internal::StatementListExecutor< 0L,1L,RAJA::RAJA::KernelPolicy<   > ,RAJA::RAJA::internal::makeInitialLoopTypes< class RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple<   >  >  , camp::decay<  >  >  > > ::exec((std::forward< RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple<   >  >  , camp::decay<  >  > & > (data__195)));
rose_inline_end__196:
        ;
      }
      {
        struct RAJA::RAJA::util::PluginContext p__198 = context;
        for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
          auto rose_temp__232 =  * plugin;
          class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__235;
          {
            const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__233 = &rose_temp__232;
            {
              rose_temp__235 = (this__233 -> object);
              goto rose_inline_end__234;
            }
rose_inline_end__234:
            ;
          }
          rose_temp__235 ->  postLaunch (p__198);
        }
rose_inline_end__199:
        ;
      }
rose_inline_end__113:
      ;
    }
rose_inline_end__40:
    ;
  }
  {
    struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Cview__47 = (Cview);
    int N__48 = N;
    bool match = true;
    for (int row = 0; row < N__48; ++row) {
      for (int col = 0; col < N__48; ++col) {
        if (std::abs(Cview__47(row,col) - (row * col * N__48)) > 10e-12) {
          match = false;
        }
      }
    }
    if (match) {
      std::cout<<;
    }
    else {
      std::cout<<;
    }
rose_inline_end__49:
    ;
  }
  std::cout<<;
  memset(C,0,(N * N) * sizeof(double ));
  //-------------end-------------
  using EXEC_POL6a = RAJA::RAJA::KernelPolicy<   > ;
  {
    struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > rose_temp__62;
    {
      RAJA::RangeSegment &args__58 = col_range;
      RAJA::RangeSegment &args__59 = row_range;
      RAJA::RangeSegment &args__60 = dot_range;
      {
        rose_temp__62 = camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  > ,class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  > ,class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  > > (std::forward< RAJA::RangeSegment & > (args__58),std::forward< RAJA::RangeSegment & > (args__58),std::forward< RAJA::RangeSegment & > (args__58));
        goto rose_inline_end__61;
      }
rose_inline_end__61:
      ;
    }
    struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&segments__51 = rose_temp__62;
    struct camp::tuple< double  > &&params__52 = camp::tuple< double > {0.0};
    class &&bodies__53 =  [=] (double &dot)
    {
      dot = 0.0;
    };
    class &&bodies__54 =  [=] (int col,int row,int k,double &dot)
    {
      dot +=  Aview(row,k) *  Bview(k,col);
    };
    class &&bodies__55 =  [=] (int col,int row,double &dot)
    {
      Cview(row,col) = dot;
    };
    struct RAJA::RAJA::util::PluginContext rose_temp__119;
    {
      {
        rose_temp__119 = RAJA::RAJA::util::PluginContext{camp::resources::v1::Platform(1)};
        goto rose_inline_end__118;
      }
rose_inline_end__118:
      ;
    }
    struct RAJA::RAJA::util::PluginContext context = rose_temp__119;
    {
      struct RAJA::RAJA::util::PluginContext p__121 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__200 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__203;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__201 = &rose_temp__200;
          {
            rose_temp__203 = (this__201 -> object);
            goto rose_inline_end__202;
          }
rose_inline_end__202:
          ;
        }
        rose_temp__203 ->  preLaunch (p__121);
      }
rose_inline_end__122:
      ;
    }
    using segment_tuple_t = RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type ;
    using param_tuple_t = camp::decay< class camp::tuple< double  >  > ;
    using loop_data_t = struct RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple< double  >  >  , camp::decay<  >  , camp::decay<  >  , camp::decay<  >  > ;
    decltype(make_wrapped_tuple_impl((forward< class camp::tuple< TypedRangeSegment< Index_type  , make_signed_t< strip_index_type_t< Index_type  >  >  >  , TypedRangeSegment< Index_type  , make_signed_t< strip_index_type_t< Index_type  >  >  >  , TypedRangeSegment< Index_type  , make_signed_t< strip_index_type_t< Index_type  >  >  >  >  > ()),camp::int_seq< camp::idx_t  , 0L , 1L , 2L > {})) rose_temp__126;
    {
      struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&t__124 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (segments__51);
      {
        {
          struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &&t__205 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__124);
          camp::idx_seq<   > __206 = {};
          {
            {
              camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__248;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__246 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 0L,"index out of range");
                {
                  auto rose_temp__325 = static_cast < struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__246 . base);
                  {
                    struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__326 = &rose_temp__325;
                    {
                      rose_temp__248 = this__326 -> val;
                      goto rose_inline_end__327;
                    }
rose_inline_end__327:
                    ;
                  }
                  goto rose_inline_end__247;
                }
rose_inline_end__247:
                ;
              }
              auto rose_temp__241 = rose_temp__248;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__244;
              {
                camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__242 = &rose_temp__241;
                {
                  rose_temp__244 = (this__242 -> m_begin);
                  goto rose_inline_end__243;
                }
rose_inline_end__243:
                ;
              }
              camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__256;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__254 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 0L,"index out of range");
                {
                  auto rose_temp__328 = static_cast < struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__254 . base);
                  {
                    struct camp::internal::tuple_storage< 0L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__329 = &rose_temp__328;
                    {
                      rose_temp__256 = this__329 -> val;
                      goto rose_inline_end__330;
                    }
rose_inline_end__330:
                    ;
                  }
                  goto rose_inline_end__255;
                }
rose_inline_end__255:
                ;
              }
              auto rose_temp__249 = rose_temp__256;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__252;
              {
                camp::tuple_element_t< 0L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__250 = &rose_temp__249;
                {
                  rose_temp__252 = (this__250 -> m_end);
                  goto rose_inline_end__251;
                }
rose_inline_end__251:
                ;
              }
              struct RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > &&args__237 = RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator ,RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType > {rose_temp__244,rose_temp__252};
              camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__264;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__262 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 1L,"index out of range");
                {
                  auto rose_temp__331 = static_cast < struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__262 . base);
                  {
                    struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__332 = &rose_temp__331;
                    {
                      rose_temp__264 = this__332 -> val;
                      goto rose_inline_end__333;
                    }
rose_inline_end__333:
                    ;
                  }
                  goto rose_inline_end__263;
                }
rose_inline_end__263:
                ;
              }
              auto rose_temp__257 = rose_temp__264;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__260;
              {
                camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__258 = &rose_temp__257;
                {
                  rose_temp__260 = (this__258 -> m_begin);
                  goto rose_inline_end__259;
                }
rose_inline_end__259:
                ;
              }
              camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__272;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__270 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 1L,"index out of range");
                {
                  auto rose_temp__334 = static_cast < struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__270 . base);
                  {
                    struct camp::internal::tuple_storage< 1L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__335 = &rose_temp__334;
                    {
                      rose_temp__272 = this__335 -> val;
                      goto rose_inline_end__336;
                    }
rose_inline_end__336:
                    ;
                  }
                  goto rose_inline_end__271;
                }
rose_inline_end__271:
                ;
              }
              auto rose_temp__265 = rose_temp__272;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__268;
              {
                camp::tuple_element_t< 1L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__266 = &rose_temp__265;
                {
                  rose_temp__268 = (this__266 -> m_end);
                  goto rose_inline_end__267;
                }
rose_inline_end__267:
                ;
              }
              struct RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > &&args__238 = RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator ,RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType > {rose_temp__260,rose_temp__268};
              camp::tuple_element_t< 2L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__280;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__278 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 2L,"index out of range");
                {
                  auto rose_temp__337 = static_cast < struct camp::internal::tuple_storage< 2L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__278 . base);
                  {
                    struct camp::internal::tuple_storage< 2L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__338 = &rose_temp__337;
                    {
                      rose_temp__280 = this__338 -> val;
                      goto rose_inline_end__339;
                    }
rose_inline_end__339:
                    ;
                  }
                  goto rose_inline_end__279;
                }
rose_inline_end__279:
                ;
              }
              auto rose_temp__273 = rose_temp__280;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__276;
              {
                camp::tuple_element_t< 2L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__274 = &rose_temp__273;
                {
                  rose_temp__276 = (this__274 -> m_begin);
                  goto rose_inline_end__275;
                }
rose_inline_end__275:
                ;
              }
              camp::tuple_element_t< 2L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > &rose_temp__288;
              {
                struct camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > &t__286 = std::forward< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > (t__205);
                using camp::internal::tpl_get_store;
                static_assert(camp::tuple_size< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > > ::value > 2L,"index out of range");
                {
                  auto rose_temp__340 = static_cast < struct camp::internal::tuple_storage< 2L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > & >  (t__286 . base);
                  {
                    struct camp::internal::tuple_storage< 2L , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  > *this__341 = &rose_temp__340;
                    {
                      rose_temp__288 = this__341 -> val;
                      goto rose_inline_end__342;
                    }
rose_inline_end__342:
                    ;
                  }
                  goto rose_inline_end__287;
                }
rose_inline_end__287:
                ;
              }
              auto rose_temp__281 = rose_temp__288;
              RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator rose_temp__284;
              {
                camp::tuple_element_t< 2L , camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  >  > *this__282 = &rose_temp__281;
                {
                  rose_temp__284 = (this__282 -> m_end);
                  goto rose_inline_end__283;
                }
rose_inline_end__283:
                ;
              }
              struct RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > &&args__239 = RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator ,RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType > {rose_temp__276,rose_temp__284};
              {
                rose_temp__126 = camp::tuple< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > ,class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > ,class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  > > (std::forward< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  >  > (args__237),std::forward< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  >  > (args__237),std::forward< class RAJA::Span< RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::iterator  , RAJA::TypedRangeSegment< RAJA::Index_type ,RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  > > ::IndexType  >  > (args__237));
                goto rose_inline_end__240;
              }
rose_inline_end__240:
              ;
            }
            goto rose_inline_end__207;
          }
rose_inline_end__207:
          ;
        }
        goto rose_inline_end__125;
      }
rose_inline_end__125:
      ;
    }
    loop_data_t loop_data(rose_temp__126,std::forward< class camp::tuple< double  >  > (params__52),std::forward<   > (bodies__53),std::forward<   > (bodies__53),std::forward<   > (bodies__53));
    using loop_types_t = RAJA::RAJA::internal::makeInitialLoopTypes< class RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple< double  >  >  , camp::decay<  >  , camp::decay<  >  , camp::decay<  >  >  > ;
    {
      struct RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple< double  >  >  , camp::decay<  >  , camp::decay<  >  , camp::decay<  >  > &data__128 = loop_data;
      RAJA::internal::StatementListExecutor< 0L,1L,RAJA::RAJA::KernelPolicy<   > ,RAJA::RAJA::internal::makeInitialLoopTypes< class RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple< double  >  >  , camp::decay<  >  , camp::decay<  >  , camp::decay<  >  >  > > ::exec((std::forward< RAJA::internal::LoopData< RAJA::IterableWrapperTuple< camp::decay< class camp::tuple< class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  , class RAJA::TypedRangeSegment< RAJA::Index_type  , RAJA::make_signed_t< RAJA::strip_index_type_t< RAJA::Index_type  >  >  >  >  > > ::type  , camp::decay< class camp::tuple< double  >  >  , camp::decay<  >  , camp::decay<  >  , camp::decay<  >  > & > (data__128)));
rose_inline_end__129:
      ;
    }
    {
      struct RAJA::RAJA::util::PluginContext p__131 = context;
      for (auto plugin = RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::begin(); plugin != RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::end();  ++ plugin) {
        auto rose_temp__208 =  * plugin;
        class std::shared_ptr< class RAJA::RAJA::util::PluginStrategy  > rose_temp__211;
        {
          const RAJA::RAJA::util::Registry< class RAJA::RAJA::util::PluginStrategy > ::entry *this__209 = &rose_temp__208;
          {
            rose_temp__211 = (this__209 -> object);
            goto rose_inline_end__210;
          }
rose_inline_end__210:
          ;
        }
        rose_temp__211 ->  postLaunch (p__131);
      }
rose_inline_end__132:
      ;
    }
rose_inline_end__56:
    ;
  }
  {
    struct RAJA::View< double  , class RAJA::detail::LayoutBase_impl< camp::make_idx_seq_t< 2L >  , RAJA::Index_type  , -1L >  , double * > Cview__64 = (Cview);
    int N__65 = N;
    bool match = true;
    for (int row = 0; row < N__65; ++row) {
      for (int col = 0; col < N__65; ++col) {
        if (std::abs(Cview__64(row,col) - (row * col * N__65)) > 10e-12) {
          match = false;
        }
      }
    }
    if (match) {
      std::cout<<;
    }
    else {
      std::cout<<;
    }
rose_inline_end__66:
    ;
  }
  std::cout<<;
  return 0;
}
  template < typename T >
void checkResult ( T * C, int N )
{
  bool match = true;
  for ( int row = 0; row < N; ++ row ) {
    for ( int col = 0; col < N; ++ col ) {
      if ( std :: abs ( C [ col + N * row ] - row * col * N ) > (9.999999999999999395e-12) ) {
        match = false;
      }
    }
  }
  if ( match ) {
    std :: cout << "\n\t result -- PASS\n";
  } else {
    std :: cout << "\n\t result -- FAIL\n";
  }
}
  template < typename T >
void checkResult ( RAJA :: View < T, RAJA :: Layout < DIM > > Cview, int N )
{
  bool match = true;
  for ( int row = 0; row < N; ++ row ) {
    for ( int col = 0; col < N; ++ col ) {
      if ( std :: abs ( Cview ( row, col ) - row * col * N ) > (9.999999999999999395e-12) ) {
        match = false;
      }
    }
  }
  if ( match ) {
    std :: cout << "\n\t result -- PASS\n";
  } else {
    std :: cout << "\n\t result -- FAIL\n";
  }
}
  template < typename T >
void printResult ( T * C, int N )
{
  std :: cout << std :: endl;
  for ( int row = 0; row < N; ++ row ) {
    for ( int col = 0; col < N; ++ col ) {
      std :: cout << "C(" << row << "," << col << ") = "
        << C [ col + N * row ] << std :: endl;
    }
  }
  std :: cout << std :: endl;
}
  template < typename T >
void printResult ( RAJA :: View < T, RAJA :: Layout < DIM > > Cview, int N )
{
  std :: cout << std :: endl;
  for ( int row = 0; row < N; ++ row ) {
    for ( int col = 0; col < N; ++ col ) {
      std :: cout << "C(" << row << "," << col << ") = "
        << Cview ( row, col ) << std :: endl;
    }
  }
  std :: cout << std :: endl;
}
